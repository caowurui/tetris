#pragma once

#include <raylib.h>

//--------To be deleted--------
namespace past
{
    //--------PHOTO RELATED--------
    const int PHOTO_SIZE = 18;

    //--------GAME FUNCTIONALITIES--------
    extern enum GameMode { START /*,TODELETE,MOVING*/, GAMEOVER } mode;
    extern bool pause;
    const int SQUARE_SIZE = 20;
    const int speed = 10;
    const int GridX = 10;
    const int GridY = 19;
    typedef struct GridSquare
    {
        enum State { EMPTY, MOVING /*,STATIC,TO_BE_DELETED*/ } state;
    } GridSquare;
    extern GridSquare grid[GridX][GridY];
    extern GridSquare now[4][4];
    extern GridSquare coming[4][4];
    struct _myPos
    {
        int x, y;
    };
    extern _myPos nowPos;

    void GetComing();

    void InitGame();
    void Rotate();
    void Drop();
    bool isCol();

    void UpdateGame();

    void DrawGame();

    //--------WINDOW RELATED--------
    const int screenwidth = SQUARE_SIZE * (GridX + 8);
    const int screenheight = SQUARE_SIZE * (GridY + 2);
    const char title[] = "TETRIS";
    const short fps = 60;

};

//--------My Change---------
class myGame
{
    int screenWidth, screenHeight;
    void initGame();
public:
    myGame(int width, int height);
    void start();
    ~myGame();
private:
    void UnloadGame();
};
