#include <genesis.h>
#include "base/game.h"
#include "splash_scene.h"

int main(bool hardReset)
{
    Game_loadScene(SplashScene_create());
    return Game_run(hardReset);
}

