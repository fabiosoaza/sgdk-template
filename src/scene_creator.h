#ifndef _SCENE_CREATOR_
#define _SCENE_CREATOR_

#include <genesis.h>
#include "base/game.h"

enum SceneType
{
    SPLASH_SCENE,
    LEVEL_SCENE,
    START_SCENE,
    TEST_SCENE
};

typedef enum SceneType SceneType;

Scene *SceneCreator_create(SceneType scene);


#endif //_SCENE_CREATOR_