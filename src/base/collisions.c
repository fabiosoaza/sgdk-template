#include <genesis.h>
#include "collisions.h"

bool __checkCollision(Box2DCollision a, Box2DCollision b) {
    if (a.x + a.w < b.x || b.x + b.w < a.x)
        return FALSE;  // Não há sobreposição horizontal
    
    if (a.y + a.h < b.y || b.y + b.h < a.y)
        return FALSE;  // Não há sobreposição vertical
    
    return TRUE;  // Há colisão
}

bool Collisions_boxCollided(Box2DCollision a, Box2DCollision b)
{

    s16 elementALeft = a.x;
    s16 elementARight = a.x + a.w;
    s16 elementBLeft = b.x;
    s16 elementBRight = b.x + b.w;

    s16 elementATop = a.y;
    s16 elementABottom = a.y + a.h;
    s16 elementBTop = b.y;
    s16 elementBBottom = b.y + b.h;

    if (elementARight > elementBLeft &&
        elementALeft < elementBRight &&
        elementABottom > elementBTop &&
        elementATop < elementBBottom)
    {
        return TRUE;
    }

    return FALSE;
}

Box2DCollision Collisions_createAdjustedCollisionBox(Box2DCollision box, Box2DCollision adjustment)
{
    return (Box2DCollision){.x = box.x + adjustment.x, .y = box.y + adjustment.y, .w = adjustment.w, .h = adjustment.h};
};

bool Collisions_checkCollisions(int totalHitboxes1, Box2DCollision hitboxes1[totalHitboxes1], int totalHitboxes2, Box2DCollision hitboxes2[totalHitboxes2])
{

    
    for (int i = 0; i < totalHitboxes1; i++)
    {
        for (int j = 0; j < totalHitboxes2; j++)
        {
            if(__checkCollision(hitboxes1[i], hitboxes2[j])){
               return TRUE;     
            }
        }
    }
    return FALSE;
}









