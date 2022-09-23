#include <genesis.h>

#include "game.h"

void __gameInit();
void __gameUpdate();
void __gameDraw();
void __gameEventInputHandler(u16, u16, u16);

static Game __INSTANCE;

bool Game_isPlaying(Game *game)
{
    return game->state == PLAYING;
}

bool Game_isPaused(Game *game)
{
    return game->state == PAUSED;
}

bool Game_isGameOver(Game *game)
{
    return game->state == GAME_OVER;
}

void Game_pause(Game *game)
{
    if (game->state == PLAYING || game->state == PAUSED)
    {
        game->state = game->state == PAUSED ? PLAYING : PAUSED;
    }
}

void Game_loadScene(Scene *scene)
{
    if (__INSTANCE.scene != NULL)
    {
        free(__INSTANCE.scene);
        __INSTANCE.scene = NULL;
    }
    if (scene != NULL)
    {
        __INSTANCE.scene = scene;
        __INSTANCE.loadSceneInit = TRUE;
    }
}

int Game_run(bool hardReset)
{
    __gameInit();

    while (TRUE)
    {
        if (__INSTANCE.loadSceneInit == TRUE && __INSTANCE.scene != NULL && __INSTANCE.scene->init != NULL)
        {
            __INSTANCE.loadSceneInit = FALSE;
            __INSTANCE.scene->init(&__INSTANCE);
        }
        __gameUpdate();
        __gameDraw();
        // always call this method at the end of the frame
        SYS_doVBlankProcess();
    }

    return 0;
}

void __gameInit()
{
    JOY_init();
    JOY_setEventHandler(&__gameEventInputHandler);
    SPR_init();
}
void __gameUpdate()

{
    if (__INSTANCE.scene != NULL && __INSTANCE.scene->update != NULL)
    {
        __INSTANCE.scene->update(&__INSTANCE);
    }
}
void __gameDraw()
{
    if (__INSTANCE.scene != NULL && __INSTANCE.scene->draw != NULL)
    {
        __INSTANCE.scene->draw(&__INSTANCE);
    }
}

void __gameEventInputHandler(u16 joy, u16 changed, u16 state)
{

    if (__INSTANCE.scene != NULL && __INSTANCE.scene->onInputEvent != NULL)
    {
        __INSTANCE.scene->onInputEvent(&__INSTANCE, joy, changed, state);
    }
}