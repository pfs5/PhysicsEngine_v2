//
// Created by patrik on 20.07.17.
//

#include "Application.h"
#include "Display.h"
#include "../Physics/Physics.h"
#include "../Physics/Collisions.h"
#include "../util/Util.h"
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

float checkSeparation (GameObject *a, GameObject *b, sf::Vector2f normal) {
    // Object a
    float max_a = std::numeric_limits<float>::min();
    float min_a = std::numeric_limits<float>::max();
    for (int i=0; i<a->getPointCount(); i++) {
        float projection = Util::dotProduct(a->getPoint(i), normal);
        if (projection > max_a) {
            max_a = projection;
        }
        if (projection < min_a) {
            min_a = projection;
        }
    }

    // Object b
    float max_b = std::numeric_limits<float>::min();
    float min_b = std::numeric_limits<float>::max();
    for (int i=0; i<b->getPointCount(); i++) {
        float projection = Util::dotProduct(b->getPoint(i), normal);
        if (projection > max_b) {
            max_b = projection;
        }
        if (projection < min_b) {
            min_b = projection;
        }
    }

    // Check separation
    return fminf(max_a - min_b, max_b - min_a);
}

// return value : positive = collision depth ; negative = no collision
float narrowCollisionDetection (GameObject *a, GameObject *b, sf::Vector2f &normal) {
    float minDistance = std::numeric_limits<float>::max();

    for (std::vector<sf::Vector2f>::iterator it = a->getNormals().begin(); it != a->getNormals().end(); it++) {
        float distance = checkSeparation(a, b, *it);
        if (distance <= 0) {
            return distance;
        } else if (distance < minDistance) {
            minDistance = distance;
            normal = *it;
        }
    }

    for (std::vector<sf::Vector2f>::iterator it = b->getNormals().begin(); it != b->getNormals().end(); it++) {
        float distance = checkSeparation(a, b, *it);
        if (distance <= 0) {
            return distance;
        } else if (distance < minDistance) {
            minDistance = distance;
            normal = *it;
        }
    }


    return minDistance;
}

void collisionDetection(std::vector<GameObject*> objects) {
    // Broad phase
    for (int i = 0; i < objects.size(); i++) {
        AABB *a = objects[i]->getAABB();
        for (int j = i + 1; j < objects.size(); j++) {
            AABB *b = objects[j]->getAABB();
            if (Collisions::AABBvsAABB(*a, *b)) {
                objects[i]->setColor(sf::Color::Red);
                objects[j]->setColor(sf::Color::Red);

                // Narrow phase
                sf::Vector2f normal;
                float distance = narrowCollisionDetection(objects[i], objects[j], normal);
                std::cout << "distance : " << distance << std::endl;
                if (distance > 0) {
                    objects[i]->setColor(sf::Color::Cyan);
                    objects[j]->setColor(sf::Color::Cyan);

                    // Move objects from collision. If one static, move one double the distance
                    sf::Vector2f displacement = distance * normal;
                    int orientation = (Util::dotProduct(objects[j]->getPosition() - objects[i]->getPosition(), normal) > 0) ? 1 : -1;
                    float k1 = (objects[j]->getRigidBody()) ? (-orientation * 0.5f) : -orientation;
                    float k2 = (objects[j]->getRigidBody()) ? (orientation * 0.5f) : orientation;

                    if (objects[i]->getRigidBody()) {
                        objects[i]->move(k1 * displacement);
                    }
                    if (objects[j]->getRigidBody()) {
                        objects[j]->move(k2 * displacement);
                    }
                }
            } else {
                objects[i]->setColor(sf::Color::White);
                objects[j]->setColor(sf::Color::White);
            }
        }
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
            float dy = 0.5f * Physics::Gravity * powf(dt, 2) * (int) rb->hasGravity() + velocity.y * dt;
            float dx = velocity.x * dt;
            (*it)->move(sf::Vector2f(dx, dy));

            // Update velocity
            velocity += sf::Vector2f (0.f, Physics::Gravity * dt * (int) rb->hasGravity());
            rb->setVelocity(velocity);
        }

        // Collision detection
        collisionDetection(gameObjects);
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

