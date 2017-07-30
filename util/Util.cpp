//
// Created by patrik on 22.07.17.
//

#include <SFML/System.hpp>
#include <iostream>
#include <cmath>
#include "Util.h"

namespace Util {
    int fcompare(float f1, float f2) {
        return (int) (f1 - f2 > Util::ZERO_TRESH);
    }

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

    sf::Vector2f &rotatePoint(sf::Vector2f &v, float angle) {
        angle *= M_PI / 180.f;

        float x_rot = v.x * cosf(angle) - v.y * sinf(angle);
        float y_rot = v.x * sinf(angle) + v.y * cosf(angle);

        v.x = x_rot;
        v.y = y_rot;

        return v;
    }

}
