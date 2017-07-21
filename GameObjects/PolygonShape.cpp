//
// Created by patrik on 21.07.17.
//

#include "PolygonShape.h"
#include "../main/Display.h"
#include "../util/Util.h"

#include <cmath>
#include <iostream>

void initializeShape(sf::ConvexShape &shape) {
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::White);
}

AABB calculateAABB(sf::ConvexShape &shape) {
    float x_min = std::numeric_limits<float>::max();
    float y_min = std::numeric_limits<float>::max();
    float x_max = std::numeric_limits<float>::min();
    float y_max = std::numeric_limits<float>::min();

    for (int i=0; i<shape.getPointCount(); i++) {
        sf::Vector2f p = shape.getPoint(i);
        if (p.x < x_min) {
            x_min = p.x;
        }
        if (p.x > x_max) {
            x_max = p.x;
        }
        if (p.y < y_min) {
            y_min = p.y;
        }
        if (p.y > y_max) {
            y_max = p.y;
        }
    }

    return AABB (sf::Vector2f (x_min, y_min), sf::Vector2f (x_max - x_min, y_max - y_min));
}

PolygonShape::PolygonShape() {
    initializeShape(m_shape);

    m_shape.setPosition(0.f, 0.f);

}

PolygonShape::PolygonShape(sf::Vector2f position, float radius, int n) {
    initializeShape(m_shape);

    m_shape.setPosition(position);
    m_shape.setPointCount(n);
    float angle = 2.f * (float) M_PI / n;
    for (int i=0; i<n; i++) {
        float x = radius * sinf(angle * (i + 1));
        float y = radius * cosf(angle * (i + 1));
        m_shape.setPoint(i, sf::Vector2f(x, y));
    }

    m_aabb = calculateAABB(m_shape);
    m_isAABBValid = true;
}

PolygonShape::PolygonShape(std::vector<sf::Vector2f> points) {
    initializeShape(m_shape);

    m_shape.setPosition(0.f, 0.f);
    m_shape.setPointCount(points.size());
    for (int i=0; i<points.size(); i++) {
        m_shape.setPoint(i, points[i] - points[0]);
    }

    m_aabb = calculateAABB(m_shape);
    m_isAABBValid = true;
}

void PolygonShape::input() {
    if (m_mouseFollow) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(Display::getWindow());
        m_shape.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
    }
}

void PolygonShape::update(float dt) {

}

void PolygonShape::draw() {
    Display::draw(m_shape);

    sf::RectangleShape aabbShape = m_aabb.shape;
    aabbShape.setPosition(aabbShape.getPosition() + m_shape.getPosition());
    Display::draw(aabbShape);
}

void PolygonShape::setMouseFollow(bool mouseFollow) {
    m_mouseFollow = mouseFollow;
}

RigidBody *PolygonShape::getRigidBody() {
    return nullptr;
}

void PolygonShape::setRigidBody(RigidBody *rb) {

}

AABB *PolygonShape::getAABB() {
    if (!m_isAABBValid) {
        m_aabb = calculateAABB(m_shape);
        m_isAABBValid = true;
    }

    return &m_aabb;
}

void PolygonShape::move(sf::Vector2f distance) {

}
