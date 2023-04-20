#include <vector>

#pragma once

class Snake
{
private:
  std::vector<std::vector<int>> body;
  int dir;

  int lastX;
  int lastY;

  bool gameOver;

public:
  std::vector<std::vector<std::string>> setSnake(std::vector<std::vector<std::string>>, const int &, const char &);
  std::vector<std::vector<std::string>> removeLastSnakePixel(std::vector<std::vector<std::string>>, const char &);

  int getDir() const { return dir; };
  void setDir(int direction) { dir = direction; }

  int getSnakeHeadX() const { return body.at(0).at(0); }
  int getSnakeHeadY() const { return body.at(0).at(1); }

  std::vector<std::vector<int>> getSnakeBody() const { return body; }

  bool isGameOver() const { return gameOver; }

  void growSnake();

  // constructor
  Snake(const int &, const int &, const int &);
};

Snake::Snake(const int &startX, const int &startY, const int &startDir)
{
  body = {{startX, startY}, {startX - 1, startY}, {startX - 2, startY}, {startX - 3, startY}, {startX - 4, startY}};
  dir = startDir;

  gameOver = false;
}

std::vector<std::vector<std::string>> Snake::setSnake(std::vector<std::vector<std::string>> canvas, const int &canvasSizeWithoutBorder, const char &snakeChar)
{
  // update intern

  lastX = body[body.size() - 1][0];
  lastY = body[body.size() - 1][1];
  for (int i = body.size() - 1; i >= 1; i--)
  {
    body.at(i).at(0) = body.at(i - 1).at(0); // x
    body.at(i).at(1) = body.at(i - 1).at(1); // y
  }

  switch (dir)
  {
  case 0:
    body.at(0).at(1)--;
    break;
  case 1:
    body.at(0).at(0)--;

    break;
  case 2:
    body.at(0).at(1)++;
    break;
  case 3:
    body.at(0).at(0)++;
    break;
  }

  // check if player lost
  for (int i = 0; i < body.size(); i++)
  {
    if ((body.at(0) == body.at(i)) && (i != 0))
    {
      gameOver = true;
    }   
  }
  

  // update graphicly
  for (int i = 0; i < body.size(); i++)
  {
    std::vector<int> element = body.at(i);
    if (i == 0 && (element.at(0) >= canvasSizeWithoutBorder + 1 || element.at(0) <= 0 || element.at(1) >= canvasSizeWithoutBorder + 1 || element.at(1) <= 0))
    {
      gameOver = true;
    }

    canvas[element.at(1)][element.at(0)] = snakeChar;
  }
  return canvas;
}

std::vector<std::vector<std::string>> Snake::removeLastSnakePixel(std::vector<std::vector<std::string>> canvas, const char &emptyChar)
{
  // update graphicly
  std::vector<int> last = body.at(body.size() - 1);
  canvas[last.at(1)][last.at(0)] = emptyChar;
  return canvas;
}

void Snake::growSnake() {
  body.push_back({lastX, lastY});
}