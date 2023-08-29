#include <genesis.h>
#include "base/game.h"
#include "base/utils.h"
#include "splash_scene.h"
#include "scene_creator.h"
#include <resources.h>
#include "configs.h"

static int __frameCounter = 0;


void SplashScene_init(Game *game)
{
    game->state = GAME_BOOTING;
    VDP_loadTileSet(splash.tileset, 1, DMA);
    PAL_setPalette(PAL1, splash.palette->data, DMA);
    int tileCols = 56 / 8;
    int tileRows = 24 / 8;
    int rowIndex = 20;
    int colIndex = 14;

    VDP_fillTileMapRectInc(BG_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, 1), 17, 13, 7, 3);
}


void SplashScene_update(Game *game) {
    if (ENABLE_SPLASH) {
        if (__frameCounter < SPLASH_FRAMES_DURATION) {
            __frameCounter++;
            return;
        }
    }
    __frameCounter = 0;
    Utils_resetScreen();
    Game_loadScene(SceneCreator_create(START_SCENE));
}
