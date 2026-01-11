#include <ncurses.h>
#include <thread>
#include <chrono>
#include <string>
#include <memory>

#include "terminal.h"
#include "mode.h"
#include "gameObject.h"
#include "game.h"
#include "player.h"

void executeCommand(Game& game, const std::string& command) {
    if (command == "q") {
        game.exit();
    }
}

int main() {
    Terminal term;
    Game game;
    game.gameObjects.push_back(std::make_unique<Player>());
    std::string commandBuffer;

    while (!game.should_exit) {
        clear();
        curs_set(0);

        const auto now = std::chrono::system_clock::now();
        const auto epoch = now.time_since_epoch();
        const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

        mvprintw(1,0,"System time: %lld", milliseconds.count());

        for (auto& gameObject: game.gameObjects) {
            gameObject->draw();
        }

        if (game.mode == Mode::COMMAND) {
            term.savePostion();
            mvprintw(LINES - 1, 0, ":%s", commandBuffer.c_str());
            curs_set(1);
        }

        int key;
        while ((key = getch()) != ERR) {
            if (game.mode == Mode::NORMAL) {
                for (auto& gameObject: game.gameObjects) {
                    gameObject->onKeyPress(key);
                }
                switch(key) {
                    case 'q':
                        game.exit();
                        break;
                    case ':':
                        game.mode = Mode::COMMAND;
                        break;
                }
            }
            else if (game.mode == Mode::COMMAND) {
                switch(key) {
                    case 10:
                    case KEY_ENTER: // Enter
                        game.mode = Mode::NORMAL;
                        executeCommand(game, commandBuffer);
                        commandBuffer.clear();
                        break;
                    case 27: // Escape
                        game.mode = Mode::NORMAL;
                        commandBuffer.clear();
                        break;
                    case 8:
                    case 127:
                    case KEY_BACKSPACE: // Backspace
                        if (commandBuffer.empty()) {
                            game.mode = Mode::NORMAL;
                        } else {
                            commandBuffer.pop_back();
                        }
                        break;
                    default:
                        commandBuffer.push_back(key);
                        break;
                }
            }
        }

        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
    }

    return 0;
}
