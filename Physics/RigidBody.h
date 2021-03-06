//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_RIGIDBODY_H
#define PHYSICSENGINE2_RIGIDBODY_H


#include <SFML/System.hpp>

class RigidBody {
    float m_mass;
    sf::Vector2f m_velocity;
    bool m_hasGravity;

public:
    RigidBody() : m_mass{0.f}, m_hasGravity{true} {};
    RigidBody(float mass) : m_mass{mass}, m_hasGravity{true} {};
    RigidBody(float mass, bool gravity) : m_mass{mass}, m_hasGravity{gravity} {};

    const float getMass() { return m_mass; };
    void setMass(float mass) { m_mass = mass; };

    sf::Vector2f getVelocity() {return m_velocity;};
    void setVelocity(sf::Vector2f &velocity) {m_velocity = velocity;};

    bool hasGravity() {return m_hasGravity;};
    void setGravity(bool gravity) {m_hasGravity = gravity;};
};


#endif //PHYSICSENGINE2_RIGIDBODY_H
