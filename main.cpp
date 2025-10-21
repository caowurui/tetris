#include <raylib.h>
#include "maps.h"

//--------main--------
int main(void)
{
    myGame game(GetScreenWidth(),GetScreenHeight());
    game.start();
    return 0;
}
