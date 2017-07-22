#include <iostream>
#include <cmath>
#include "Application.h"
#include "../GameObjects/RectangleObject.h"
#include "../GameObjects/PolygonShape.h"

void initObjects(Application &app) {
//    GameObject *rectangle1 = new RectangleObject(100, 100, 150, 200);
//    rectangle1->setRigidBody(new RigidBody());
//    app.addGameObject(rectangle1);

    GameObject *poly1 = new PolygonShape(sf::Vector2f(300.f, 300.f), 50.f, 4);
    app.addGameObject(poly1);

    std::vector<sf::Vector2f> points2;
    points2.push_back(sf::Vector2f (190.f, 180.f));
    points2.push_back(sf::Vector2f (250.f, 150.f));
    points2.push_back(sf::Vector2f (300.f, 220.f));
    points2.push_back(sf::Vector2f (240.f, 250.f));
    points2.push_back(sf::Vector2f (180.f, 230.f));

    GameObject *poly2 = new PolygonShape(points2);
    poly2->setMouseFollow(true);
    app.addGameObject(poly2);

    GameObject *poly3 = new PolygonShape(sf::Vector2f(600.f, 300.f), 100.f, 6);
    poly3->setRigidBody(new RigidBody(0, false));
    app.addGameObject(poly3);

}

int main() {
    std::cout << "> starting game" << std::endl;
    Application app;

    initObjects(app);

    app.runMainLoop();

    return 0;
}