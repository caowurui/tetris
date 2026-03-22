/*
 * This file was just used to store the global datas,
 * such as the height of the window or the fps of the
 * game, so that every game file could share the same
 * variables without defining many times.
 */

#include <raylib.h>

// window
int fps = 20;
int screenWidth = 400;
int screenHeight = 800;
Color BackgroundColor = RAYWHITE;

char title[]="Hello, world!";

// ground
// extern constexpr int GridX = 10;
// extern constexpr int GridY = 40;

// block
int BlockSize = 20;

// feature
// the time per 'turn'
double rate = 0.2;

// score
int score = 0;
int linesCleared = 0;
extern const int points[] = {0, 100, 300, 500, 800};

