//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_RECTANGLEOBJECT_H
#define PHYSICSENGINE2_RECTANGLEOBJECT_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "GameObject.h"

class RectangleObject: public GameObject {
    sf::RectangleShape m_shape;
    sf::Vector2f m_position;
    RigidBody *m_rigidbody;
public:
    RectangleObject();
    RectangleObject(float x, float y, float width, float height);

    ~RectangleObject() override;

    void input() override;
    void update(float dt) override;
    void draw() override;

    RigidBody *getRigidBody() override;

    void setRigidBody(RigidBody *rb) override;

    void move(sf::Vector2f distance) override;
};


#endif //PHYSICSENGINE2_RECTANGLEOBJECT_H
