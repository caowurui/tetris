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
    if(IsKeyDown(KEY_LEFT))
        Left();
    if(IsKeyDown(KEY_RIGHT))
        Right();
    if(IsKeyDown(KEY_UP))
        Rotate();
    if(!Fall())
    {
        Generate();
    }
}

void myGame::Generate()
{
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

void myGame::Left()
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
    if(!top)return;
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(i==0)f=false;
        if(map[i-1][j].solid())f=false;
    }
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(f)
        {
            map[i-1][j]=map[i][j];
            map[i][j].clear();
        }
    }
}

void myGame::Right()
{
    bool f=true;
    int top=0;
    int store[10][2];
    for(int i=GridX-1;i>=0;--i)
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
    if(!top)return;
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(i==GridX-1)f=false;
        if(map[i+1][j].solid())f=false;
    }
    for(int t=0;t<top;++t)
    {
        int i=store[t][0];
        int j=store[t][1];
        if(f)
        {
            map[i+1][j]=map[i][j];
            map[i][j].clear();
        }
    }
}

void myGame::Rotate()
{
    // Find all moving blocks and store their positions
    bool movingBlocks[GridX][GridY] = {false};
    int blockCount = 0;
    int blockPositions[10][2]; // Store positions of moving blocks

    for(int i = 0; i < GridX; i++)
    {
        for(int j = 0; j < GridY; j++)
        {
            if(map[i][j].moving())
            {
                movingBlocks[i][j] = true;
                blockPositions[blockCount][0] = i;
                blockPositions[blockCount][1] = j;
                blockCount++;
            }
        }
    }

    if(blockCount == 0) return;

    // Find the bounding box of the moving blocks
    int minX = GridX, maxX = -1, minY = GridY, maxY = -1;
    for(int i = 0; i < blockCount; i++)
    {
        int x = blockPositions[i][0];
        int y = blockPositions[i][1];
        if(x < minX) minX = x;
        if(x > maxX) maxX = x;
        if(y < minY) minY = y;
        if(y > maxY) maxY = y;
    }

    // Calculate center of the bounding box
    int centerX = (minX + maxX) / 2;
    int centerY = (minY + maxY) / 2;

    // Calculate new positions after 90° clockwise rotation
    // For 90° clockwise rotation around center (cx, cy):
    // x' = cx + (y - cy)
    // y' = cy - (x - cx)

    // Create new positions array
    int newPositions[10][2];
    for(int i = 0; i < blockCount; i++)
    {
        int x = blockPositions[i][0];
        int y = blockPositions[i][1];
        newPositions[i][0] = centerX + (y - centerY);
        newPositions[i][1] = centerY - (x - centerX);
    }

    // Check if all new positions are valid (within bounds and not colliding with solid blocks)
    bool valid = true;
    for(int i = 0; i < blockCount; i++)
    {
        int newX = newPositions[i][0];
        int newY = newPositions[i][1];

        // Check if new position is within bounds
        if(newX < 0 || newX >= GridX || newY < 0 || newY >= GridY)
        {
            valid = false;
            break;
        }

        // Check if new position is not solid
        if(map[newX][newY].solid())
        {
            valid = false;
            break;
        }
    }

    // If positions are valid, update the map
    if(valid)
    {
        // Store the color information before clearing
        Color colors[10];
        for(int i = 0; i < blockCount; i++)
        {
            int x = blockPositions[i][0];
            int y = blockPositions[i][1];
            colors[i] = map[x][y].color;
        }

        // Clear original positions
        for(int i = 0; i < blockCount; i++)
        {
            int x = blockPositions[i][0];
            int y = blockPositions[i][1];
            map[x][y].clear();
        }

        // Set new positions with preserved color information
        for(int i = 0; i < blockCount; i++)
        {
            int newX = newPositions[i][0];
            int newY = newPositions[i][1];
            map[newX][newY] = GridBlock(colors[i]);
        }
    }
}

myGame::~myGame()
{
    this->UnloadGame();
    CloseWindow();
}

void myGame::UnloadGame()
{

}
