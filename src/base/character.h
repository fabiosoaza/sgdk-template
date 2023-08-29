#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <genesis.h>
#include "collisions.h"
#include "entity.h"



 struct Character
{
   Entity base;
   bool isMoving;
   bool isOnFloor;
   bool isAlive;
   int tries;//lives
   int maxTries;//lives
   fix16 health;
   fix16 maxHealth;
   fix16 gravity;
   int score;
   int maxScore;
   int minScore;

};

typedef struct Character Character;


#endif // _CHARACTER_H_