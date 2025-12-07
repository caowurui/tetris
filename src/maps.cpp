#include "maps.h"

char title[]="Hello, world!";

myGame::myGame(int width, int height)
{
    SetTargetFPS(fps);
    InitWindow(screenWidth, screenHeight, title);
    this->initGame();
}

void myGame::initGame()
{

}

void myGame::start()
{
    while (!WindowShouldClose())
    {

    }
}

myGame::~myGame()
{
    this->UnloadGame();
    CloseWindow();
}

//--------private--------
void myGame::UnloadGame()
{

}
