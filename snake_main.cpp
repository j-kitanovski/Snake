#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include "game.h"
#include "snake.h"
#include "food.h"

int main()
{
    // game loop
    while (true)
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
        Game game = Game(0x57, 0x41, 0x53, 0x44, 254, ' ', 25);
        // snake
        Snake snake = Snake(game.getCanvasSize() / 2, game.getCanvasSize() / 2, 3);
        // food manager
        FoodManager foodManager = FoodManager();
        while (true)
        {
            if (foodManager.getNoFoodExists())
            {
                foodManager.generateFood(snake.getSnakeBody(), game.getCanvasSizeWithoutBorder());
                game.setCanvas(foodManager.setFood(game.getCanvas(), game.getFoodChar()));
            }

            snake.setDir(game.getDirKeyPressed(snake.getDir()));
            if (foodManager.foodCollide(snake.getSnakeHeadX(), snake.getSnakeHeadY()))
            {
                game.setCanvas(foodManager.removeFood(game.getCanvas(), game.getEmptyChar()));
                snake.growSnake();
            }
            else
            {
                game.setCanvas(snake.removeLastSnakePixel(game.getCanvas(), game.getEmptyChar()));
            }
            game.setCanvas(snake.setSnake(game.getCanvas(), game.getCanvasSizeWithoutBorder(), game.getSnakeChar()));

            if (snake.isGameOver())
            {
                // game over
                Sleep(2000);
                system("cls");
                Sleep(750);
                break;
            }

            game.drawCanvas();
            game.sleep();
        }
    }

    system("pause");
}