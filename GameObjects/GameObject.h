//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_GAMEOBJECT_H
#define PHYSICSENGINE2_GAMEOBJECT_H

#include "../Physics/RigidBody.h"
#include "../Physics/AABB.h"

class GameObject {
public:
    virtual ~GameObject(){};

    virtual void input() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    /**
     * Make the objects position follow the mouse cursor.
     * Useful for testing purposes.
     * @param mouseFollow Boolean value
     */
    virtual void setMouseFollow(bool mouseFollow) = 0;

    /**
     * Returns pointer to rigid body object.
     * @return Pointer to rigid body object. nullptr if there is no rigid body.
     */
    virtual RigidBody *getRigidBody() = 0;

    /**
     * Sets the rigid body for the object. Object should be initialized by
     * client on the heap. The GameObject object is responsible for object deletion.
     * @param rb Pointer to rigidbody object.
     */
    virtual void setRigidBody(RigidBody *rb) = 0;

    /**
     * Returns pointer to AABB in global space
     * @return AABB pointer
     */
    virtual AABB *getAABB () = 0;

    /**
     * Returns vector of shape sides normals (normalized)
     * @return Reference to std::vector or normals
     */
    virtual std::vector<sf::Vector2f> &getNormals() = 0;

    /**
     * Returns number of object points
     * @return Number of points
     */
    virtual int getPointCount() = 0;

    /**
     * Return point at given index in global space
     * @param index Point index
     * @return Point
     */
    virtual sf::Vector2f getPoint (int index) = 0;

    /**
     * Returns position of object in global space
     * @return Position as vector
     */
    virtual sf::Vector2f getPosition () = 0;

    /**
     * Move game object for given distance
     * @param distance Move distance
     */
    virtual void move (sf::Vector2f distance) = 0;

    /**
     * Rotate game object for given angle in positive direction (CCW)
     * @param angle Angle in degrees
     */
    virtual void rotate (float angle) = 0;

    /**
     * Sets color for object
     * @param color Color
     */
    virtual void setColor (sf::Color color) = 0;
};

#endif //PHYSICSENGINE2_GAMEOBJECT_H
