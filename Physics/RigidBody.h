//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_RIGIDBODY_H
#define PHYSICSENGINE2_RIGIDBODY_H


#include <SFML/System.hpp>

class RigidBody {
    float m_mass;
    sf::Vector2f m_velocity;

public:
    RigidBody() : m_mass{0.f} {};
    RigidBody(float mass) : m_mass{mass} {};

    const float getMass() { return m_mass; };
    void setMass(float mass) { m_mass = mass; };

    sf::Vector2f getVelocity() {return m_velocity;};
    void setVelocity(sf::Vector2f &velocity) {m_velocity = velocity;};
};


#endif //PHYSICSENGINE2_RIGIDBODY_H
