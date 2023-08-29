#include <genesis.h>
#include "base/game.h"
#include "base/utils.h"
#include "base/entity.h"
#include "start_scene.h"

static bool __updateGraphics = FALSE;
static int __frameCounter = 0;
static int __randomValue = 0;

static char *__buttonName = NULL;
static __moving = FALSE;

const u32 squareTileData[8] =
    {
        0x11111111,
        0x10000001,
        0x10000001,
        0x10000001,
        0x10000001,
        0x10000001,
        0x10000001,
        0x11111111};

Entity square = (Entity){
    .enabled = TRUE,
    .x = 16,
    .y = 48,
    .width = 10,
    .height = 10,
    .velX = FIX16(0),
    .velY = FIX16(0)};

void StartScene_init(Game *game)
{

    VDP_clearTileMap(BG_B, 0, 20 * 14, FALSE);
    game->state = GAME_TITLE;
    VDP_setTextPlane(BG_A);
    VDP_loadTileData(squareTileData, 1, 1, 0);
    PAL_setColor(1, RGB24_TO_VDPCOLOR(0xFF0000));

    VDP_setTileMapXY(BG_B, 1, square.x / 8, square.y / 8);
}

void StartScene_update(Game *game)
{
    if (__frameCounter == 60)
    {
        __frameCounter = 0;
        __randomValue = Utils_randomInt(1, 100);
    }
    else
    {
        __updateGraphics = TRUE;
        __frameCounter++;
    }

    if (__moving == TRUE)
    {
        Entity_move(&square);
        __moving = FALSE;
    }
}

void StartScene_draw(Game *game)
{
    if (__updateGraphics)
    {

        Utils_showFormattedText("FPS %02d", 1, 1, SYS_getFPS());

        Utils_showFormattedText("RANDOM VALUE BETWEEN 1 AND 100 %03d", 1, 2, __randomValue);

        if (__buttonName != NULL)
        {
            Utils_showFormattedText("LAST BUTTON PRESSED %s", 1, 3, __buttonName);
            free(__buttonName);
            __buttonName = NULL;
        }

        Utils_showFormattedText("SQUARE[x=%03d, y=%03d]", 1, 4, square.x, square.y);

        VDP_clearPlane(BG_B, FALSE);
        VDP_setTileMapXY(BG_B, 1, square.x / 8, square.y / 8);

        __updateGraphics = FALSE;
    }
}

void StartScene_onInputEvent(Game *game, u16 joy, u16 changed, u16 state)
{

    if (joy == JOY_1)
    {

        __updateGraphics = TRUE;
        if (changed & state)
        {
            __buttonName = Utils_getButtonName(Utils_getButtonCode(state));
        }

        if (state & BUTTON_LEFT)
        {
            if (square.x - 8 >= 8)
            {
                __moving = TRUE;
                square.velX = FIX16(-8);
                square.velY = FIX16(0);
            }
        }

        else if (state & BUTTON_RIGHT)
        {
            if (square.x + 8 <= 308)
            {
                __moving = TRUE;
                square.velX = FIX16(8);
                square.velY = FIX16(0);
            }
        }

        else if (state & BUTTON_UP)
        {
            if (square.y - 8 >= 48)
            {
                __moving = TRUE;
                square.velY = FIX16(-8);
                square.velX = FIX16(0);
            }
        }

        else if (state & BUTTON_DOWN)
        {
            if (square.y + 8 <= 214)
            {
                __moving = TRUE;
                square.velY = FIX16(8);
                square.velX = FIX16(0);
            }
        }
        else if ((changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) | (changed & BUTTON_UP) | (changed & BUTTON_DOWN))
        {
            __moving = FALSE;
        }
    }
}
