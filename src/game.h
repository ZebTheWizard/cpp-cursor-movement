#pragma once

#include "mode.h"
#include "gameObject.h"
#include <memory>
#include <vector>

class Game {
public:
    Mode mode;
    bool should_exit;
    std::vector<std::unique_ptr<GameObject> > gameObjects;
    Game() {
        mode = Mode::NORMAL;
    };
    void exit() {
        should_exit = true;
    }
};
