#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <genesis.h>

typedef enum _Direction
{
    NONE,
    TOP,
    RIGHT,
    BOTTOM,
    LEFT

} Direction;

typedef struct _Entity
{
    int x;
    int y;
    int oldX;
    int oldY;
    u16 width;
    u16 height;
    int velX;
    int velY;
    bool enabled;
} Entity;

s16 Entity_getLeft(Entity el);
s16 Entity_getRight(Entity el);
s16 Entity_getTop(Entity el);
s16 Entity_getBottom(Entity el);

int Entity_getOldLeft(Entity el);
int Entity_getOldRight(Entity el);
int Entity_getOldTop(Entity el);
int Entity_getOldBottom(Entity el);

void Entity_setX(Entity *el, s16 px);
void Entity_setY(Entity *el, s16 py);

void Entity_moveX(Entity *el, s16 px);
void Entity_moveY(Entity *el, s16 py);

bool Entity_collided(Entity el1, Entity el2);
bool Entity_collidedFromTop(Entity principal, Entity b);
bool Entity_collidedFromBottom(Entity principal, Entity b);
bool Entity_collidedFromLeft(Entity principal, Entity b);
bool Entity_collidedFromRight(Entity principal, Entity b);

#endif // _ENTITY_H_