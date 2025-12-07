#pragma once

#include <raylib.h>

class myGame
{
    static const int fps = 60;
    int screenWidth, screenHeight;

    static const int GridX=10;
    static const int GridY=19;
    struct GridSqare{
        enum State{EMPTY}state;
    };
    GridSqare grid[GridX][GridY];
    GridSqare now[4][4];
    GridSqare coming[4][4];

    void initGame();

public:
    myGame(int width, int height);
    void start();
    ~myGame();
private:
    void UnloadGame();
};
