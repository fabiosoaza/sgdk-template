#ifndef _GAME_H_
#define _GAME_H_

typedef enum _GameState
{
    BOOTING,
    PAUSED,
    PLAYING,
    GAME_OVER,
    TITLE,
    BEATED,
    DEAD,
    RESTART_LEVEL
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
};


void Game_loadScene(Scene * scene);
int Game_run(bool hardReset);

bool Game_isPlaying(Game *game);
bool Game_isPaused(Game *game);
bool Game_isGameOver(Game *game);
void Game_pause(Game *game);


#endif //_GAME_H_