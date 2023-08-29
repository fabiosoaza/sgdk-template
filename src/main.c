#include <genesis.h>
#include "base/game.h"
#include "scene_creator.h"

int main(bool hardReset)
{
    Game_loadScene(SceneCreator_create(SPLASH_SCENE));
    return Game_run(hardReset);
}
