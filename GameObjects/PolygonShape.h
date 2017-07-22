//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_POLYGONSHAPE_H
#define PHYSICSENGINE2_POLYGONSHAPE_H


#include <SFML/Graphics/ConvexShape.hpp>
#include "GameObject.h"

class PolygonShape: public GameObject {
    sf::ConvexShape m_shape;
    AABB m_aabbLocal;
    AABB m_aabbGlobal;
    std::vector<sf::Vector2f> m_normals;
    RigidBody *m_rigidbody;

    bool m_mouseFollow;
    bool m_isAABBValid = false;
    bool m_areNormalsValid = false;
public:
    PolygonShape();
    PolygonShape(sf::Vector2f position, float radius, int n);
    PolygonShape(std::vector<sf::Vector2f> points);
    ~PolygonShape() {delete m_rigidbody;};

    void input() override;
    void update(float dt) override;
    void draw() override;

    void setMouseFollow(bool mouseFollow) override;

    RigidBody *getRigidBody() override;
    void setRigidBody(RigidBody *rb) override;

    AABB *getAABB() override;
    std::vector<sf::Vector2f> &getNormals() override;

    int getPointCount() override;

    sf::Vector2f getPoint(int index) override;

    void move(sf::Vector2f distance) override;
    sf::Vector2f getPosition() override;

    void setColor(sf::Color color) override;
};


#endif //PHYSICSENGINE2_POLYGONSHAPE_H
