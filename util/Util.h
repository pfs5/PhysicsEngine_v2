//
// Created by patrik on 22.07.17.
//

#ifndef PHYSICSENGINE2_UTIL_H
#define PHYSICSENGINE2_UTIL_H

#include <SFML/System.hpp>
#include <iostream>

namespace Util {
    const float ZERO_TRESH = 1e-6;

    /**
     * Compare function for float numbers using the ZERO_TRESH constant
     * @param f1 First float
     * @param f2 Second float
     * @return Regular compare function return :
     * f1 > f2  -> return positive int
     * f1 < f2  -> return negative int
     * f1 == f2 -> return zero
     */
    int fcompare(float f1, float f2);
    /**
     * Prints the parameter vector to stdout.
     *
     * @param v The vector to be printed
     */

    void printSFVector (sf::Vector2i v);

    /**
     * Prints the parameter vector to stdout.
     *
     * @param v The vector to be printed
     */
    void printSFVector (sf::Vector2f v);

    /**
     * Calculates dot product of two input vectors as
     * x1*x2 + y1*y2
     *
     * @param v1 First vector
     * @param v2 Second vector
     * @return Dot product of input vectors
     */
    float dotProduct (sf::Vector2f v1, sf::Vector2f v2);

    /**
     * Calculates magnitude of input vector as sqrt(x^2 + y^2)
     *
     * @param v Input vector
     * @return Vector magnitude / length
     */
    float magnitude (sf::Vector2f v);

    /**
     * Rotates the input vector in place for angle around (0,0)
     * in positive (CCW) direction
     *
     * @param v Input vector reference
     * @param angle Rotation angle in DEGREES
     * @return Reference to rotated vector
     */
    sf::Vector2f &rotatePoint(sf::Vector2f &v, float angle);
}

#endif //PHYSICSENGINE2_UTIL_H
