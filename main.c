#include <raylib.h>

//--------PHOTO RELATED--------
#define PHOTO_SIZE 18

//--------GAME FUNCTIONALITIES--------
enum GameMode{START/*,TODELETE,MOVING*/,GAMEOVER}mode=START;
bool pause=false;
#define SQUARE_SIZE 20
#define speed 10
#define GridX 10
#define GridY 19
typedef struct GridSquare{
    enum State{EMPTY,MOVING/*,STATIC,TO_BE_DELETED*/}state;
}GridSquare;
GridSquare grid[GridX][GridY];
GridSquare now[4][4];
GridSquare coming[4][4];
struct{
    int x,y;
}nowPos;

void GetComing(){
    int rand=GetRandomValue(0,6);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            coming[i][j].state=EMPTY;
        }
    switch(rand){
    case 0:{coming[1][1].state=coming[1][2].state=coming[2][1].state=coming[2][2].state=MOVING;break;}//Cube
    case 1:{coming[1][0].state=coming[1][1].state=coming[1][2].state=coming[2][2].state=MOVING;break;}//-7
    case 2:{coming[1][2].state=coming[2][0].state=coming[2][1].state=coming[2][2].state=MOVING;break;}//_|
    case 3:{coming[0][1].state=coming[1][1].state=coming[2][1].state=coming[3][1].state=MOVING;break;}//|
    case 4:{coming[1][0].state=coming[1][1].state=coming[1][2].state=coming[2][1].state=MOVING;break;}//T
    case 5:{coming[1][1].state=coming[2][1].state=coming[2][2].state=coming[3][2].state=MOVING;break;}//|/|
    case 6:{coming[1][2].state=coming[2][2].state=coming[2][1].state=coming[3][1].state=MOVING;break;}//N
    }
}

void InitGame(){
    GetComing();
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            now[i][j]=coming[i][j];
    nowPos.x=GridX/2-2;nowPos.y=0;
    GetComing();
    for(int i=0;i<GridX;i++)
        for(int j=0;j<GridY;j++)
            grid[i][j].state=EMPTY;
}
void Rotate(){

}
void Drop(){

}
bool isCol(){
    return false;
}

void UpdateGame(){
    static int tick=0;
    if(mode!=GAMEOVER){
        if(IsKeyPressed(KEY_P))
            pause=!pause;
        if(!pause){
            tick++;
            if(tick%speed==0){
                tick-=speed;
                GridSquare tmp[4][4];
                for(int i=0;i<4;i++)for(int j=0;j<4;j++)tmp[i][j]=now[i][j];
                Drop();
                if(isCol()){

                }
            }
        }
    }
}

void DrawGame(){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(0,0,SQUARE_SIZE,(GridY+2)*SQUARE_SIZE,GRAY);
    DrawRectangle((GridX+1)*SQUARE_SIZE,0,SQUARE_SIZE,(GridY+2)*SQUARE_SIZE,GRAY);
    DrawRectangle(0,(GridY+1)*SQUARE_SIZE,(GridX+2)*SQUARE_SIZE,SQUARE_SIZE,GRAY);

    DrawRectangle(SQUARE_SIZE*(GridX+2),0,SQUARE_SIZE,SQUARE_SIZE*6,GRAY);
    DrawRectangle(SQUARE_SIZE*(GridX+2),0,SQUARE_SIZE*6,SQUARE_SIZE,GRAY);
    DrawRectangle(SQUARE_SIZE*(GridX+2),SQUARE_SIZE*5,SQUARE_SIZE*6,SQUARE_SIZE,GRAY);
    DrawRectangle(SQUARE_SIZE*(GridX+7),0,SQUARE_SIZE,SQUARE_SIZE*6,GRAY);

    for(int i=0;i<GridX;i++)
        for(int j=0;j<GridY;j++){
            if(grid[i][j].state!=EMPTY)
            DrawRectangle(SQUARE_SIZE*i+PHOTO_SIZE,SQUARE_SIZE*i+PHOTO_SIZE,PHOTO_SIZE,PHOTO_SIZE,DARKGRAY);
        }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(coming[i][j].state!=EMPTY){
                DrawRectangle(SQUARE_SIZE*(GridX+3+j)+(SQUARE_SIZE-PHOTO_SIZE)/2,SQUARE_SIZE*(i+1)+(SQUARE_SIZE-PHOTO_SIZE)/2,PHOTO_SIZE,PHOTO_SIZE,DARKGRAY);
            }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(now[i][j].state!=EMPTY){
                DrawRectangle((nowPos.x+j)*SQUARE_SIZE+(SQUARE_SIZE-PHOTO_SIZE)/2,(nowPos.y+i)*SQUARE_SIZE+(SQUARE_SIZE-PHOTO_SIZE)/2,PHOTO_SIZE,PHOTO_SIZE,DARKGRAY);
            }

    EndDrawing();
}


void UnloadGame(){
}

//--------WINDOW RELATED--------
const int screenwidth=SQUARE_SIZE*(GridX+8);
const int screenheight=SQUARE_SIZE*(GridY+2);
const char title[]="TETRIS";
const short fps=60;

//--------main--------
int main(void)
{
    SetTargetFPS(fps);
    InitWindow(screenwidth,screenheight,title);
    InitGame();
    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }
    UnloadGame();
    CloseWindow();
    return 0;
}
