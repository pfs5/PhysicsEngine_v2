//
// Created by patrik on 21.07.17.
//

#ifndef PHYSICSENGINE2_DISPLAY_H
#define PHYSICSENGINE2_DISPLAY_H

#include <SFML/Graphics.hpp>

namespace Display {
    void init();

    void clear(const sf::Color& colour = {0, 0, 0});
    void display();
    void draw(const sf::Drawable& drawable);

    void checkWindowEvents();

    bool isOpen();

    sf::RenderWindow &getWindow();

    constexpr uint16_t HEIGHT = 1096;    // 720
    constexpr uint16_t WIDTH = 1208;    // 1208
    const std::string TITLE = "Window";

    const float UPS = 60;   // 60
}

#endif //PHYSICSENGINE2_DISPLAY_H
