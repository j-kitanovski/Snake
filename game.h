#pragma once
#include "windows.h"
#include <vector>
#include <string>

class Game
{
private:
    // chars
    char SNAKE_CHAR;
    char EMPTY_CHAR;
    char FOOD_CHAR = '*';

    char BORDER_TOP = 220;
    char BORDER_LEFT = 219;
    char BORDER_BOTTOM = 223;
    char BORDER_RIGHT = 219;

    // keys
    int KEY_UP;
    int KEY_LEFT;
    int KEY_DOWN;
    int KEY_RIGHT;

    bool isKeyPressed(const int &);
    // game canvas
    int CANVAS_SIZE_WIHOUT_BORDER;
    int CANVAS_SIZE;

    std::vector<std::vector<std::string>> gameCanvas;

    // sleep
    int sleepTime = 50;

public:
    // getter functions for constants

    int getCanvasSizeWithoutBorder() const { return CANVAS_SIZE_WIHOUT_BORDER; }
    int getCanvasSize() const { return CANVAS_SIZE; }
    char getSnakeChar() const { return SNAKE_CHAR; }
    char getEmptyChar() const { return EMPTY_CHAR; }
    char getFoodChar() const { return FOOD_CHAR; }

    // setter and getter for canvas

    std::vector<std::vector<std::string>> getCanvas() const { return gameCanvas; }
    void setCanvas(const std::vector<std::vector<std::string>> &canvas) { gameCanvas = canvas; }

    // return the direction int of the key the user pressed
    int getDirKeyPressed(const int &currentDirection);

    void drawCanvas();

    // sleep
    void sleep();

    // constructors

    Game(const int &, const int &, const int &, const int &, const char &, const char &, const int &);
    Game(const int &, const int &, const int &, const int &, const char &, const char &, const int &, const int &);
    Game(const int &, const int &, const int &, const int &, const char &, const char &, const int &, const char &,
         const char &, const char &, const char &, const int &);
};

// constructors
Game::Game(const int &keyUp, const int &keyLeft, const int &keyDown, const int &keyRight,
           const char &snakeChar, const char &emptyChar, const int &canvasSize, const char &borderTop,
           const char &borderLeft, const char &borderBottom, const char &borderRight, const int &gameLoopSleepTime)
{
    // keys
    KEY_UP = keyUp;
    KEY_LEFT = keyLeft;
    KEY_DOWN = keyDown;
    KEY_RIGHT = keyRight;

    // chars
    SNAKE_CHAR = snakeChar;
    EMPTY_CHAR = emptyChar;

    BORDER_TOP = borderTop;
    BORDER_LEFT = borderLeft;
    BORDER_BOTTOM = borderBottom;
    BORDER_RIGHT = borderRight;

    // canvas
    CANVAS_SIZE_WIHOUT_BORDER = canvasSize;
    CANVAS_SIZE = canvasSize + 2;

    gameCanvas.resize(CANVAS_SIZE);
    for (std::vector<std::string> &row : gameCanvas)
    {
        row.resize(CANVAS_SIZE);
    }

    // Draw top and bottom borders
    for (int x = 0; x < CANVAS_SIZE; x++)
    {
        gameCanvas[0][x] = BORDER_TOP;
        gameCanvas[CANVAS_SIZE - 1][x] = BORDER_BOTTOM;
    }

    // Draw left and right borders
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        gameCanvas[y][0] = BORDER_LEFT;
        gameCanvas[y][CANVAS_SIZE - 1] = BORDER_RIGHT;
    }

    // Fill interior with empty spaces
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        for (int x = 1; x < CANVAS_SIZE - 1; x++)
        {
            gameCanvas[y][x] = EMPTY_CHAR;
        }
    }

    sleepTime = gameLoopSleepTime;
}

Game::Game(const int &keyUp, const int &keyLeft, const int &keyDown, const int &keyRight,
           const char &snakeChar, const char &emptyChar, const int &canvasSize, const int &gameLoopSleepTime)
{
    // keys
    KEY_UP = keyUp;
    KEY_LEFT = keyLeft;
    KEY_DOWN = keyDown;
    KEY_RIGHT = keyRight;

    // chars
    SNAKE_CHAR = snakeChar;
    EMPTY_CHAR = emptyChar;

    // canvas
    CANVAS_SIZE_WIHOUT_BORDER = canvasSize;
    CANVAS_SIZE = canvasSize + 2;

    gameCanvas.resize(CANVAS_SIZE);
    for (std::vector<std::string> &row : gameCanvas)
    {
        row.resize(CANVAS_SIZE);
    }

    // Draw top and bottom borders
    for (int x = 0; x < CANVAS_SIZE; x++)
    {
        gameCanvas[0][x] = BORDER_TOP;
        gameCanvas[CANVAS_SIZE - 1][x] = BORDER_BOTTOM;
    }

    // Draw left and right borders
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        gameCanvas[y][0] = BORDER_LEFT;
        gameCanvas[y][CANVAS_SIZE - 1] = BORDER_RIGHT;
    }

    // Fill interior with empty spaces
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        for (int x = 1; x < CANVAS_SIZE - 1; x++)
        {
            gameCanvas[y][x] = EMPTY_CHAR;
        }
    }

    sleepTime = gameLoopSleepTime;
}

Game::Game(const int &keyUp, const int &keyLeft, const int &keyDown, const int &keyRight,
           const char &snakeChar, const char &emptyChar, const int &canvasSize)
{
    // keys
    KEY_UP = keyUp;
    KEY_LEFT = keyLeft;
    KEY_DOWN = keyDown;
    KEY_RIGHT = keyRight;

    // chars
    SNAKE_CHAR = snakeChar;
    EMPTY_CHAR = emptyChar;

    // canvas
    CANVAS_SIZE_WIHOUT_BORDER = canvasSize;
    CANVAS_SIZE = canvasSize + 2;

    gameCanvas.resize(CANVAS_SIZE);
    for (std::vector<std::string> &row : gameCanvas)
    {
        row.resize(CANVAS_SIZE);
    }

    // Draw top and bottom borders
    for (int x = 0; x < CANVAS_SIZE; x++)
    {
        gameCanvas[0][x] = BORDER_TOP;
        gameCanvas[CANVAS_SIZE - 1][x] = BORDER_BOTTOM;
    }

    // Draw left and right borders
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        gameCanvas[y][0] = BORDER_LEFT;
        gameCanvas[y][CANVAS_SIZE - 1] = BORDER_RIGHT;
    }

    // Fill interior with empty spaces
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        for (int x = 1; x < CANVAS_SIZE - 1; x++)
        {
            gameCanvas[y][x] = EMPTY_CHAR;
        }
    }

    sleepTime = -42;
}

// methods

bool Game::isKeyPressed(const int &keyCode)
{
    return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
}

int Game::getDirKeyPressed(const int &currentDirection)
{
    bool canSwitch = false;
    if (isKeyPressed(KEY_UP) && currentDirection != 2)
    {
        return 0;
    }
    else if (isKeyPressed(KEY_LEFT) && currentDirection != 3)
    {
        return 1;
    }
    else if (isKeyPressed(KEY_DOWN) && currentDirection != 0)
    {
        return 2;
    }
    else if (isKeyPressed(KEY_RIGHT) && currentDirection != 1)
    {
        return 3;
    }
    return currentDirection;
}

void Game::drawCanvas()
{
    system("cls");

    static std::string backBuffer = "";
    static std::string frontBuffer = "";
    for (int y = 0; y < gameCanvas.size(); y++)
    {
        for (int x = 0; x < gameCanvas.size(); x++)
        {
            std::string stringToAdd = "";
            stringToAdd += gameCanvas[y][x];
            if (y == 0 && x != CANVAS_SIZE - 1)
            {
                stringToAdd += BORDER_TOP;
            }
            else if (y == CANVAS_SIZE - 1 && x != CANVAS_SIZE - 1)
            {
                stringToAdd += BORDER_BOTTOM;
            }
            else
            {
                stringToAdd += ' ';
            }

            backBuffer += stringToAdd;
        }
        backBuffer += "\n";
    }
    std::swap(backBuffer, frontBuffer);
    backBuffer.clear();
    std::cout << frontBuffer;
}

void Game::sleep()
{
    if (sleepTime == -42)
    {
        sleepTime = 500 / CANVAS_SIZE_WIHOUT_BORDER;
    }

    Sleep(sleepTime);
}
