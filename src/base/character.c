#include <genesis.h>
#include "character.h"

/*
Box2DCollision _createBox2DCollision(Entity entity)
{
    return (Box2DCollision){.x = entity.x, .w = entity.width, .y = entity.y, .h = entity.height};
}
*/

/**
 * Convert hitboxes from relative to absolute position

Box2DCollision * Character_createAdjustedHitBoxes(Character *character){
     Box2DCollision characterBoundingBox = _createBox2DCollision(character->base);
    
       Box2DCollision * adjustedHitBoxes =  (Box2DCollision *)malloc( character->hitboxesCount * sizeof(Box2DCollision));
     
     for (u8  i = 0; i < character->hitboxesCount; i++)
     {
        adjustedHitBoxes[i] = Collisions_createAdjustedCollisionBox(characterBoundingBox, character->hitboxes[i]);
        
     }
     return adjustedHitBoxes;

}

void Character_destroy(Character *character){
    free(character);
}

*/