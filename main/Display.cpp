//
// Created by patrik on 21.07.17.
//

#include "Display.h"
#include <memory>
#include <iostream>

namespace Display {

    std::unique_ptr<sf::RenderWindow> window;

    void init() {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    }

    void clear(const sf::Color &colour) {
        window->clear(colour);
    }

    void display() {
        window->display();
    }

    void draw(const sf::Drawable &drawable) {
        window->draw(drawable);
    }

    void checkWindowEvents() {
        sf::Event e;
        while (window->pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window->close();
            }
        }
    }

    bool isOpen() {
        return window->isOpen();
    }

}