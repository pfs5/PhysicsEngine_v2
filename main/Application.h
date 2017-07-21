//
// Created by patrik on 20.07.17.
//

#ifndef PHYSICSENGINE2_APPLICATION_H
#define PHYSICSENGINE2_APPLICATION_H


#include <vector>
#include <bits/unique_ptr.h>
#include "../GameObjects/GameObject.h"

class Application {
    std::vector<GameObject*> m_gameObjects;
public:
    Application();
    ~Application();

    void runMainLoop();

    void addGameObject(GameObject *o);
};


#endif //PHYSICSENGINE2_APPLICATION_H
