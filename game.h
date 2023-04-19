#pragma once
#include "windows.h"

class Game
{
public:
    const int CANVAS_SIZE_WIHOUT_BORDER = 20;
    const int CANVAS_SIZE = CANVAS_SIZE_WIHOUT_BORDER + 2;
    const char SNAKE_CHAR = 254;
    const char EMPTY_CHAR = ' ';
    bool isKeyPressed(int);
};

bool Game::isKeyPressed(int keyCode)
{
    return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}