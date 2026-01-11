#pragma once

#include <ncurses.h>

#include "position.h"
#include "gameObject.h"

class Player: public GameObject {
public:
    Position position;
    void draw() override;
    void onKeyPress(int key) override;
};
