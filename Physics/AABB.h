//
// Created by patrik on 22.07.17.
//

#ifndef PHYSICSENGINE2_AABB_H
#define PHYSICSENGINE2_AABB_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class AABB {
public:
    sf::Vector2f pos;
    sf::Vector2f size;

    sf::RectangleShape shape;

    AABB () {};
    AABB (sf::Vector2f pos, sf::Vector2f size): pos{pos}, size{size}{
        shape.setPosition(pos);
        shape.setSize(size);

        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(1.f);
        shape.setOutlineColor(sf::Color::Green);
    };
};

#endif //PHYSICSENGINE2_AABB_H
