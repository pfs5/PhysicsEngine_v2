//
// Created by patrik on 20.07.17.
//

#include "Application.h"
#include "Display.h"
#include "../Physics/Physics.h"
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <cmath>

void calculateFPS(bool print_fps) {
    static sf::Clock timer;
    static sf::Clock printTimer;
    static auto numFrames = 0;

    numFrames++;

    if (printTimer.getElapsedTime().asSeconds() >= 1.0f)
    {
        auto fps = (float)numFrames / timer.getElapsedTime().asSeconds();
        printTimer.restart();
        if (print_fps) {
            std::cout << "fps : " << fps << std::endl;
        }

        numFrames = 0;
        timer.restart();
    }
}

void input(std::vector<GameObject*> gameObjects) {
    for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)  {
        (*it)->input();
    }
}

void update(std::vector<GameObject*> gameObjects, float dt) {
    for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)  {
        (*it)->update(dt);

        // Physics
        RigidBody *rb = (*it)->getRigidBody();
        if (rb) {
            sf::Vector2f velocity = rb->getVelocity();

            // Update position
            float dy = 0.5f * Physics::Gravity * powf(dt, 2) + velocity.y * dt;
            float dx = velocity.x * dt;
            (*it)->move(sf::Vector2f(dx, dy));

            // Update velocity
            velocity += sf::Vector2f (0.f, Physics::Gravity * dt);
            rb->setVelocity(velocity);
        }
    }
}

void draw(std::vector<GameObject*> gameObjects) {
    for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)  {
        (*it)->draw();
    }
}

Application::Application() {
    Display::init();
}

Application::~Application() {
    // Delete game objects
    for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); ++it)  {
        delete (*it);
    }
}

void Application::runMainLoop() {
    sf::Clock clock;
    sf::Time accumulator;
    sf::Time dt = sf::seconds(1.f / Display::UPS);
    sf::Time max_acc = sf::seconds(0.2f);

    while(Display::isOpen()) {
        Display::checkWindowEvents();
        Display::clear();

        input(m_gameObjects);

        // Physics
        accumulator += clock.restart();

        // Clamp accumulator
        //if (accumulator > max_acc) {
        //    accumulator = max_acc;
        //}

        while (accumulator > dt) {
            update(m_gameObjects, dt.asSeconds());
            accumulator -= dt;
        }

        // Rendering
        draw(m_gameObjects);

        calculateFPS(true);
        Display::display();
    }
}

void Application::addGameObject(GameObject *o) {
    m_gameObjects.push_back(o);
}

