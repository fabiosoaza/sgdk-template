#ifndef _START_SCENE_H_
#define _START_SCENE_H_

#include "base/game.h"

Scene * StartScene_create();
void StartScene_init(Game *);
void StartScene_update(Game *);
void StartScene_draw(Game *);
void StartScene_onInputEvent(Game *, u16, u16, u16);

#endif //_START_SCENE_H_