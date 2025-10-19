#include <raylib.h>
int main()
{
    SetTargetFPS(30);
    InitWindow(800,600,"Hello, world!");
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
