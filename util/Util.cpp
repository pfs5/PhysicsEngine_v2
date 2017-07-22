//
// Created by patrik on 22.07.17.
//

#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

namespace Util {
    void printSFVector (sf::Vector2i v) {
        std::cout << v.x << " " << v.y << std::endl;
    }

    void printSFVector (sf::Vector2f v) {
        std::cout << v.x << " " << v.y << std::endl;
    }

    float dotProduct (sf::Vector2f v1, sf::Vector2f v2) {
        return v1.x * v2.x + v1.y * v2.y;
    }

    float magnitude (sf::Vector2f v) {
        return sqrtf(v.x * v.x + v.y * v.y);
    }

}
