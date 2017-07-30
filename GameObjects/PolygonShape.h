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

    bool m_mouseFollow = false;
    bool m_isAABBValid = false;
    bool m_areNormalsValid = false;
public:
    /**
     * Initialize empty polygon with no points.
     */
    PolygonShape();

    /**
     * Initialize regular polygon of n vertices and with given radius at given position.
     * The local center of mass is set at (0, 0)
     * @param position Shape position.
     * @param radius Shape radius.
     * @param n Number of vertices
     */
    PolygonShape(sf::Vector2f position, float radius, int n);

    /**
     * Initializes polygon with given std::vector of points in global space.
     * The local center of mass is set at (0, 0)
     * @param points std::vector of points in global space
     */
    PolygonShape(std::vector<sf::Vector2f> points);

    /**
     * Frees memory according to RAII
     */
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

    void rotate(float angle) override;

    sf::Vector2f getPosition() override;

    void setColor(sf::Color color) override;
};


#endif //PHYSICSENGINE2_POLYGONSHAPE_H
