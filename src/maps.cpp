#include "maps.h"
#include <raylib.h>

inline int min(int x,int y){return x<y?x:y;}

myGame::myGame(int width, int height)
{
    SetTargetFPS(fps);
    InitWindow(screenWidth, screenHeight, title);
    BlockSize=min(screenWidth/GridX,screenHeight/GridY*2);
    this->initGame();
}

void myGame::initGame()
{
    // Generate();
}


void myGame::start()
{
    while (!WindowShouldClose())
    {
        UpdateGame();

        BeginDrawing();
        this->DrawGame();
        EndDrawing();

    }
}

void myGame::UpdateGame()
{
    if(!Fall())
    {
        Generate();
    }
}

void myGame::Generate()
{
     /*
      * 青色 I
      * 黄色 O
      * 紫色或品红色 T
      * 绿色 S
      * 红色 Z
      * 蓝色 J
      * 橙色 L
      */
    int rand = GetRandomValue(1,7);
    switch(rand)
    {
        // 青色 I
        case 1:
            map[3][20]=map[4][20]=map[5][20]=map[6][20]=GridBlock(SKYBLUE);
            break;

        // 黄色 O
        case 2:
            map[4][20]=map[5][20]=map[4][21]=map[5][21]=GridBlock(YELLOW);
            break;

        // 紫色或品红色 T
        case 3:
            map[3][20]=map[4][20]=map[5][20]=map[4][21]=GridBlock(VIOLET);
            break;

        // 绿色 S
        case 4:
            map[3][20]=map[4][20]=map[4][21]=map[5][21]=GridBlock(GREEN);
            break;

        // 红色 Z
        case 5:
            map[4][20]=map[5][20]=map[3][21]=map[4][21]=GridBlock(RED);
            break;

        // 蓝色 J
        case 6:
            map[3][20]=map[4][20]=map[5][20]=map[3][21]=GridBlock(DARKBLUE);
            break;

        // 橙色 L
        case 7:
            map[3][20]=map[4][20]=map[5][20]=map[5][21]=GridBlock(ORANGE);
            break;
    }
    Fall();
}

void myGame::DrawGame()
{
    ClearBackground(BackgroundColor);
    for(int i=0;i<GridX;++i)
    {
        for(int j=0;j<GridY/2;++j)
        {
            if(!map[i][j].empty())
            {
                DrawRectangle(BlockSize*i,BlockSize*(GridY/2-j-1),BlockSize,BlockSize,map[i][j].color);
            }
        }
    }
}

bool myGame::Fall()
{
    bool f=true;
    int top=0;
    int store[10][2];
    for(int i=0;i<GridX;++i)
    {
        for(int j=0;j<GridY;++j)
        {
            if(map[i][j].moving())
            {
                store[top][0]=i,store[top][1]=j;
                top++;
            }
        }
    }
    if(!top)return false;
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(j==0)f=false;
        if(map[i][j-1].solid())f=false;
    }
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(f)
        {
            map[i][j-1]=map[i][j];
            map[i][j].clear();
        }
        else
        {
            map[i][j].stop();
        }
    }
    return f;
}

myGame::~myGame()
{
    this->UnloadGame();
    CloseWindow();
}

void myGame::UnloadGame()
{

}
