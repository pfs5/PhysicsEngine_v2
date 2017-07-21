//
// Created by patrik on 22.07.17.
//

#ifndef PHYSICSENGINE2_UTIL_H
#define PHYSICSENGINE2_UTIL_H

#include <SFML/System.hpp>
#include <iostream>

namespace Util {
    void printSFVector (sf::Vector2i v) {
        std::cout << v.x << " " << v.y << std::endl;
    }

    void printSFVector (sf::Vector2f v) {
        std::cout << v.x << " " << v.y << std::endl;
    }
}

#endif //PHYSICSENGINE2_UTIL_H
