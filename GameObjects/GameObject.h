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

    virtual void setMouseFollow(bool mouseFollow) = 0;

    virtual RigidBody *getRigidBody() = 0;
    virtual void setRigidBody(RigidBody *rb) = 0;

    virtual AABB *getAABB () = 0;

    virtual void move (sf::Vector2f distance) = 0;
};

#endif //PHYSICSENGINE2_GAMEOBJECT_H
