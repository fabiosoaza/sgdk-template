#include "scene_creator.h"
#include "splash_scene.h"
#include "start_scene.h"

Scene *__createSplashScene()
{
    Scene *ptr =  MEM_alloc(sizeof(Scene));
    ptr->init = SplashScene_init;
    ptr->update = SplashScene_update;
    ptr->draw = NULL;
    ptr->onInputEvent = NULL;
    return ptr;
}

Scene *__createStartScene()
{
    Scene *ptr = MEM_alloc(sizeof(Scene));
    ptr->init = StartScene_init;
    ptr->update = StartScene_update;
    ptr->draw = StartScene_draw;
    ptr->onInputEvent = StartScene_onInputEvent;
    return ptr;
}


Scene *SceneCreator_create(SceneType scene)
{

    switch (scene)
    {
    case SPLASH_SCENE:
        return __createSplashScene();
        break;
     case START_SCENE:
        return __createStartScene();
        break;

    default:
        return NULL;
        break;
    }
}
