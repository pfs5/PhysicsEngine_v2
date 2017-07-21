#include <iostream>
#include "Application.h"
#include "../GameObjects/RectangleObject.h"

void initObjects(Application &app) {
    GameObject *rectangle1 = new RectangleObject(100, 100, 150, 200);
    rectangle1->setRigidBody(new RigidBody());
    app.addGameObject(rectangle1);
}

int main() {
    std::cout << "> starting game" << std::endl;
    Application app;

    initObjects(app);

    app.runMainLoop();

    return 0;
}