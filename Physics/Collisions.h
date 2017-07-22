//
// Created by patrik on 22.07.17.
//

#ifndef PHYSICSENGINE2_COLLISIONS_H
#define PHYSICSENGINE2_COLLISIONS_H

#include "AABB.h"

namespace Collisions {
    bool AABBvsAABB (AABB a, AABB b) {
        if (a.pos.x + a.size.x < b.pos.x || b.pos.x + b.size.x < a.pos.x) {
            return false;
        }

        if (a.pos.y + a.size.y < b.pos.y || b.pos.y + b.size.y < a.pos.y) {
            return false;
        }

        return true;
    }
}

#endif //PHYSICSENGINE2_COLLISIONS_H
