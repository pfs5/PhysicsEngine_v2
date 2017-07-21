//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_POLYGONSHAPE_H
#define PHYSICSENGINE2_POLYGONSHAPE_H


#include <SFML/Graphics/ConvexShape.hpp>
#include "GameObject.h"

class PolygonShape: public GameObject {
    sf::ConvexShape m_shape;
    AABB m_aabb;

    bool m_mouseFollow;
    bool m_isAABBValid;
public:
    PolygonShape();
    PolygonShape(sf::Vector2f position, float radius, int n);
    PolygonShape(std::vector<sf::Vector2f> points);

    void input() override;
    void update(float dt) override;
    void draw() override;

    void setMouseFollow(bool mouseFollow) override;

    RigidBody *getRigidBody() override;
    void setRigidBody(RigidBody *rb) override;

    AABB *getAABB() override;

    void move(sf::Vector2f distance) override;
};


#endif //PHYSICSENGINE2_POLYGONSHAPE_H