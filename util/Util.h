//
// Created by patrik on 22.07.17.
//

#ifndef PHYSICSENGINE2_UTIL_H
#define PHYSICSENGINE2_UTIL_H

#include <SFML/System.hpp>
#include <iostream>

namespace Util {
    void printSFVector (sf::Vector2i v);

    void printSFVector (sf::Vector2f v);

    float dotProduct (sf::Vector2f v1, sf::Vector2f v2);
    float magnitude (sf::Vector2f v);
}

#endif //PHYSICSENGINE2_UTIL_H
