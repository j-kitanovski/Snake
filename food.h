#pragma once

#include <vector>
#include <random>
#include <chrono>

class FoodManager
{
private:
    bool noFoodExists;
    std::vector<int> foodPos;

public:
    FoodManager();

    bool getNoFoodExists() const { return noFoodExists; }

    void generateFood(const std::vector<std::vector<int>> &, const int &);
    std::vector<std::vector<std::string>> setFood(std::vector<std::vector<std::string>>, const char &);
    std::vector<std::vector<std::string>> removeFood(std::vector<std::vector<std::string>>, const char &);
    bool foodCollide(const int &, const int &);
};

// constructor
FoodManager::FoodManager()
{
    noFoodExists = true;
}

void FoodManager::generateFood(const std::vector<std::vector<int>> &snakeBody, const int &canvasSizeWithoutBorder)
{
    noFoodExists = false;
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    int mostLikelyValue = canvasSizeWithoutBorder / 2;

    int width = canvasSizeWithoutBorder / 2 - 5;

    std::uniform_int_distribution<int> distribution(mostLikelyValue - width, mostLikelyValue + width);

    while (true)
    {
        int randomX = distribution(generator);
        int randomY = distribution(generator);

        bool collide = false;

        for (int i = 0; i < snakeBody.size(); i++)
        {
            if (snakeBody.at(i).at(0) == randomX || snakeBody.at(i).at(1) == randomY)
            {
                collide = true;
            }
        }

        if (!collide)
        {
            foodPos = {randomX, randomY};
            break;
        }
    }
}

std::vector<std::vector<std::string>> FoodManager::setFood(std::vector<std::vector<std::string>> canvas, const char &foodChar)
{
    canvas.at(foodPos.at(1)).at(foodPos.at(0)) = foodChar;
    return canvas;
}

std::vector<std::vector<std::string>> FoodManager::removeFood(std::vector<std::vector<std::string>> canvas, const char &emptyChar)
{
    noFoodExists = true;
    canvas.at(foodPos.at(1)).at(foodPos.at(0)) = emptyChar;
    return canvas;
}

bool FoodManager::foodCollide(const int &snakeHeadX, const int &snakeHeadY)
{
    if (snakeHeadX == foodPos.at(0) && snakeHeadY == foodPos.at(1))
    {
        return true;
    }
    return false;
}