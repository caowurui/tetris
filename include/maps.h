#pragma once

#include <raylib.h>

// window
extern int fps;
extern int screenWidth,screenHeight;
extern char title[];

extern Color BackgroundColor;


// block
extern int BlockSize;
constexpr int GridX = 10,GridY = 40;


class GridBlock{
    bool _empty;
    bool is_running;
public:
    Color color;
    GridBlock(){is_running=false;_empty=true;color=BackgroundColor;}
    GridBlock(Color c){is_running=true;_empty=false;color=c;}
    inline void stop(){is_running=false;}
    inline bool empty(){return this->_empty;}
    inline bool moving(){return !_empty&&is_running;}
    inline bool solid(){return !_empty&&!is_running;}
    inline void clear(){is_running=false;_empty=true;color=BackgroundColor;}
};

/*
 * The main class of this game.
 */
class myGame
{
// Grid
private:
    GridBlock map[GridX][GridY];

// Initialize the game
private:
    void initGame();
public:
    myGame(const myGame &) = default;
    myGame(myGame &&) = delete;
    myGame &operator=(const myGame &) = default;
    myGame &operator=(myGame &&) = delete;
    myGame(int width, int height);

    // Game procession
private:
    void Generate();
    bool Fall(); // When cannot fall return false
    void Left();
    void Right();
    void Rotate();
private:
    void DrawGame();
    void UpdateGame();
public:
    void start();

// Game finishing
public:
    ~myGame();
private:
    void UnloadGame();
};
