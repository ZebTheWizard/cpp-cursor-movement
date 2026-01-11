#include "player.h"

void Player::draw() {
    mvprintw(position.y, position.x, "█");
}

void Player::onKeyPress(int key) {
    switch (key) {
        case KEY_RIGHT:
            if (position.x == COLS - 1) {
                position.x = 0;
            } else {
                position.x += 1;
            }
            break;
        case KEY_LEFT:
            if (position.x == 0) {
                position.x = COLS - 1;
            } else {
                position.x -= 1;
            }
            break;
        case KEY_UP:
            if (position.y == 0) {
                position.y = LINES - 1;
            } else {
                position.y -= 1;
            }
            break;
        case KEY_DOWN:
            if (position.y == LINES - 1) {
                position.y = 0;
            } else {
                position.y += 1;
            }
            break;
    }
}
