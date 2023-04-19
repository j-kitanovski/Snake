#include <vector>
#include "game.h"
#pragma once

class Snake
{
private:
  std::vector<std::vector<int>> body;
  int dir;

public:
  void Snake::setSnakePixel(std::vector<std::vector<std::string>> &canvas);
  void Snake::removeLastSnakePixel(std::vector<std::vector<std::string>> &canvas);
  Snake(const int &, const int &);
};

Snake::Snake(const int &startX, const int &startY)
{
  body = {{startX, startY}};
}

void Snake::setSnakePixel(std::vector<std::vector<std::string>> &canvas)
{
    for (int i = 0; i < body.size(); i++)
    {
        std::vector<int> element = body.at(i);
        if (i == 0 && (element.at(0) >= CANVAS_SIZE_WIHOUT_BORDER + 1 || element.at(0) <= 0 || element.at(1) >= CANVAS_SIZE_WIHOUT_BORDER + 1 || element.at(1) <= 0))
        {
            // loose
            system("pause");
            exit(0);
        }

        canvas[element.at(1)][element.at(0)] = SNAKE_CHAR;
    }

}

void Snake::removeLastSnakePixel(std::vector<std::vector<std::string>> &canvas)
{
    std::vector<int> last = body.at(body.size()-1);
    canvas[last.at(1)][last.at(0)] = EMPTY_CHAR;
}