//
// Created by patrik on 20.07.17.
//

#ifndef PHYSICSENGINE2_APPLICATION_H
#define PHYSICSENGINE2_APPLICATION_H


#include <vector>
#include <bits/unique_ptr.h>
#include "../GameObjects/GameObject.h"

namespace Grid {
    const int GRID_SPACING = 200;
    const float GRID_LINE_WIDTH = 1.f;
}

class Application {
    std::vector<GameObject*> m_gameObjects;

    bool m_drawGrid;
    std::vector<sf::RectangleShape> m_grid;
public:
    Application();
    Application(bool drawGrid);
    ~Application();

    void runMainLoop();

    void addGameObject(GameObject *o);
};


#endif //PHYSICSENGINE2_APPLICATION_H
