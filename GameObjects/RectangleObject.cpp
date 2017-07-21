//
// Created by patrik on 21.07.17.
//

#include <iostream>
#include "RectangleObject.h"
#include "../main/Display.h"

void RectangleObject::input() {

}

void RectangleObject::update(float dt) {

}

void RectangleObject::draw() {
    m_shape.setPosition(m_position);
    Display::draw(m_shape);
}

void initializeRectangle(sf::RectangleShape &rect) {
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineThickness(3.f);
}

RectangleObject::RectangleObject() {
    initializeRectangle(m_shape);
}

RectangleObject::RectangleObject(float x, float y, float width, float height) {
    m_shape.setPosition(x, y);
    m_shape.setSize(sf::Vector2f {width, height});

    m_position.x = x;
    m_position.y = y;

    initializeRectangle(m_shape);
}

RectangleObject::~RectangleObject() {
    // Memory cleanup
    if (m_rigidbody) {
        delete m_rigidbody;
    }
}

RigidBody *RectangleObject::getRigidBody() {
    return m_rigidbody;
}

void RectangleObject::setRigidBody(RigidBody *rb) {
    m_rigidbody = rb;
}

void RectangleObject::move(sf::Vector2f distance) {
    m_position += distance;
}
