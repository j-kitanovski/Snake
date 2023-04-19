#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "game.h"
#include "snake.h"

void setSnakePixel(std::vector<std::vector<std::string>> &, const int &, const int &);
void removeSnakePixel(std::vector<std::vector<std::string>> &, const int &, const int &);
void drawCanvas(const std::vector<std::vector<std::string>> &);

bool isKeyPressed(int);

const int CANVAS_SIZE_WIHOUT_BORDER = 20;
const int CANVAS_SIZE = CANVAS_SIZE_WIHOUT_BORDER + 2;
const char SNAKE_CHAR = 254;
const char EMPTY_CHAR = ' ';

int main()
{
    // menu
    std::cout << "Welcome to Snake!\n"
                 "1 Play\n"
                 "2 Quit\n"
                 "Choose an option: ";

    std::string menuInput;
    getline(std::cin, menuInput);

    if (menuInput == "2" || menuInput == "Quit" || menuInput == "quit")
    {
        return 0;
    }
    else if (menuInput == "1" || menuInput == "Play" || menuInput == "play")
    {
        system("cls");
    }
    else
    {
        return -1;
    }

    // game

    // fill canvas
    std::vector<std::vector<std::string>> gameCanvas;

    gameCanvas.resize(CANVAS_SIZE);
    for (std::vector<std::string> &row : gameCanvas)
    {
        row.resize(CANVAS_SIZE);
    }

    // Draw top and bottom borders
    for (int x = 0; x < CANVAS_SIZE; x++)
    {
        gameCanvas[0][x] = 220;
        gameCanvas[CANVAS_SIZE - 1][x] = 223;
    }

    // Draw left and right borders
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        gameCanvas[y][0] = 219;
        gameCanvas[y][CANVAS_SIZE - 1] = 219;
    }

    // Fill interior with empty spaces
    for (int y = 1; y < CANVAS_SIZE - 1; y++)
    {
        for (int x = 1; x < CANVAS_SIZE - 1; x++)
        {
            gameCanvas[y][x] = EMPTY_CHAR;
        }
    }

    // draw
    int userX = CANVAS_SIZE_WIHOUT_BORDER / 2;
    int userY = CANVAS_SIZE_WIHOUT_BORDER / 2;
    int previousX = userX;
    int previousY = userY;
    int dir = 3;
    while (true)
    {
        if (isKeyPressed(0x57) && dir != 2)
        {
            dir = 0; // up
        }
        else if (isKeyPressed(0x41) && dir != 3)
        {
            dir = 1; // left
        }
        else if (isKeyPressed(0x53) && dir != 0)
        {
            dir = 2; // down
        }
        else if (isKeyPressed(0x44) && dir != 1)
        {
            dir = 3; // right
        }

        switch (dir)
        {
        case 0:
            userY--;
            break;
        case 1:
            userX--;
            break;
        case 2:
            userY++;
            break;
        case 3:
            userX++;
            break;

        default:
            break;
        }

        removeSnakePixel(gameCanvas, previousX, previousY);
        setSnakePixel(gameCanvas, userX, userY);
        previousX = userX;
        previousY = userY;
        drawCanvas(gameCanvas);
        int sleepTime = 2000 / CANVAS_SIZE_WIHOUT_BORDER;
        Sleep(sleepTime);
    }

    system("pause");
}

void setSnakePixel(std::vector<std::vector<std::string>> &canvas, const int &x, const int &y)
{
    if (x >= CANVAS_SIZE_WIHOUT_BORDER + 1 || x <= 0 || y >= CANVAS_SIZE_WIHOUT_BORDER + 1 || y <= 0)
    {
        // loose
        system("pause");
        exit(0);
    }

    canvas[y][x] = SNAKE_CHAR;
}

void removeSnakePixel(std::vector<std::vector<std::string>> &canvas, const int &x, const int &y)
{
    canvas[y][x] = EMPTY_CHAR;
}

void drawCanvas(const std::vector<std::vector<std::string>> &canvas)
{
    system("cls");

    static std::string backBuffer = "";
    static std::string frontBuffer = "";
    for (int y = 0; y < canvas.size(); y++)
    {
        for (int x = 0; x < canvas.size(); x++)
        {
            std::string stringToAdd = "";
            stringToAdd += canvas[y][x];
            if (y == 0 && x != CANVAS_SIZE - 1)
            {
                stringToAdd += 220;
            }
            else if (y == CANVAS_SIZE - 1 && x != CANVAS_SIZE - 1)
            {
                stringToAdd += 223;
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

