#ifndef _GAME_H_
#define _GAME_H_

typedef enum _GameState
{
    GAME_BOOTING,
    GAME_PAUSED,
    GAME_PLAYING,
    GAME_OVER,
    GAME_TITLE,
    GAME_BEATED,
    GAME_DEAD,
    GAME_RESTARTING_LEVEL
}GameState;


typedef struct Game Game;
typedef struct Scene Scene;

typedef void (*Scene_action)(Game *);
typedef void (*Scene_inputEventHandler)(Game *, u16, u16, u16);

struct Scene{
    Scene_action init;
    Scene_action update;
    Scene_action draw;
    Scene_inputEventHandler onInputEvent; 

};

struct Game{
    GameState state;
    Scene * scene;
    bool loadSceneInit;
    s16 frameCounter;
};


void Game_loadScene(Scene * scene);
int Game_run(bool hardReset);

bool Game_isPlaying(Game *game);
bool Game_isPaused(Game *game);
bool Game_isGameOver(Game *game);
void Game_pause(Game *game);


#endif //_GAME_H_