#include <iostream>
#include <cmath>
#include "Application.h"
#include "../GameObjects/RectangleObject.h"
#include "../GameObjects/PolygonShape.h"
#include "../util/Util.h"

void initObjects(Application &app) {
//    GameObject *rectangle1 = new RectangleObject(100, 100, 150, 200);
//    rectangle1->setRigidBody(new RigidBody());
//    app.addGameObject(rectangle1);

    GameObject *poly1 = new PolygonShape(sf::Vector2f(100.f, 100.f), 50.f, 4);
    //poly1->setRigidBody(new RigidBody());
    //poly1->getRigidBody()->setGravity(false);
    //poly1->getRigidBody()->setAngularVelocity(1.f);
    //app.addGameObject(poly1);

    std::vector<sf::Vector2f> points2;
    points2.push_back(sf::Vector2f (190.f, 180.f));
    points2.push_back(sf::Vector2f (250.f, 150.f));
    points2.push_back(sf::Vector2f (300.f, 220.f));
    points2.push_back(sf::Vector2f (240.f, 250.f));
    points2.push_back(sf::Vector2f (180.f, 230.f));
    GameObject *poly2 = new PolygonShape(points2);
    poly2->setMouseFollow(true);
    app.addGameObject(poly2);

    std::vector<sf::Vector2f> points3;
    points3.push_back(sf::Vector2f (200.f, 200.f));
    points3.push_back(sf::Vector2f (300.f, 200.f));
    points3.push_back(sf::Vector2f (350.f, 350.f));
    points3.push_back(sf::Vector2f (200.f, 300.f));
    GameObject *poly3 = new PolygonShape(points3);
    poly3->setRigidBody(new RigidBody());
    poly3->getRigidBody()->setGravity(false);
    app.addGameObject(poly3);

    GameObject *poly4 = new PolygonShape(points3);
    poly4->setRigidBody(new RigidBody());
    poly4->move(sf::Vector2f(450.f, 100.f));
    poly4->getRigidBody()->setGravity(true);
    //app.addGameObject(poly4);

    GameObject *poly5 = new PolygonShape(points3);
    poly5->setRigidBody(new RigidBody());
    poly5->move(sf::Vector2f(450.f, 250.f));
    poly5->getRigidBody()->setGravity(true);
    //app.addGameObject(poly5);

    std::vector<sf::Vector2f> points6;
    points6.push_back(sf::Vector2f (0.f, 0.f));
    points6.push_back(sf::Vector2f (800.f, 0.f));
    points6.push_back(sf::Vector2f (800.f, 100.f));
    points6.push_back(sf::Vector2f (0.f, 100.f));
    GameObject *poly6 = new PolygonShape(points6);
    poly6->move(sf::Vector2f (100.f, 800.f));
    poly6->setRigidBody(nullptr);
    //app.addGameObject(poly6);
}

int main() {
    std::cout << "> starting game" << std::endl;
    Application app;

    initObjects(app);

    app.runMainLoop();

    return 0;
}