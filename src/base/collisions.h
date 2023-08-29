#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_

#include <genesis.h>



struct Box2DCollision
{
    s16 x;
    s16 y;
    u8 w;
    u8 h;
} ;

typedef struct Box2DCollision Box2DCollision;



bool Collisions_boxCollided(Box2DCollision a, Box2DCollision b);
Box2DCollision Collisions_createAdjustedCollisionBox(Box2DCollision box, Box2DCollision adjustment);
bool Collisions_checkCollisions(int totalHitboxes1, Box2DCollision hitboxes1[totalHitboxes1], int totalHitboxes2, Box2DCollision hitboxes2[totalHitboxes2]);

#endif // _COLLISIONS_H_