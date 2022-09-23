#include "entity.h"

s16 Entity_getLeft(Entity el)
{
    return el.x;
}
s16 Entity_getRight(Entity el)
{
    return el.x + el.width;
}

s16 Entity_getTop(Entity el)
{
    return el.y;
}

s16 Entity_getBottom(Entity el)
{
    return el.y + el.height;
}

int Entity_getOldLeft(Entity el)
{
    return el.oldX;
}

int Entity_getOldRight(Entity el)
{
    return Entity_getOldLeft(el) + el.width;
}

int Entity_getOldTop(Entity el)
{
    return el.oldY;
}

int Entity_getOldBottom(Entity el)
{
    return Entity_getOldTop(el) + el.height;
}

void Entity_setX(Entity *el, s16 px)
{
    el->oldX = el->x;
    el->x = px;
}

void Entity_setY(Entity *el, s16 py)
{
    el->oldY = el->y;
    el->y = py;
}

void Entity_move(Entity *el)
{
    Entity_setX(el, el->x + fix16ToInt(el->velX));
    Entity_setY(el, el->y + fix16ToInt(el->velY));
}

void Entity_moveX(Entity *e, s16 px)
{
    Entity_setX(e, e->x + px);
}

void Entity_moveY(Entity *e, s16 py)
{
    Entity_setY(e, e->y + py);
}

bool Entity_collided(Entity a, Entity b)
{
    if (!a.enabled || !b.enabled)
    {
        return FALSE;
    }

    s16 elementALeft = Entity_getLeft(a);
    s16 elementARight = Entity_getRight(a);
    s16 elementBLeft = Entity_getLeft(b);
    s16 elementBRight = Entity_getRight(b);

    s16 elementATop = Entity_getTop(a);
    s16 elementABottom = Entity_getBottom(a);
    s16 elementBTop = Entity_getTop(b);
    s16 elementBBottom = Entity_getBottom(b);

    if (elementARight > elementBLeft &&
        elementALeft < elementBRight &&
        elementABottom > elementBTop &&
        elementATop < elementBBottom)
    {
        return TRUE;
    }

    return FALSE;
}

bool Entity_collidedFromTop(Entity principal, Entity b)
{
    return Entity_collided(principal, b) && Entity_getOldBottom(principal) <= Entity_getTop(b) // was not colliding
           && Entity_getBottom(principal) > Entity_getTop(b);
}

bool Entity_collidedFromBottom(Entity principal, Entity b)
{
    return Entity_collided(principal, b) && Entity_getOldTop(principal) >= Entity_getBottom(b) // was not colliding
           && Entity_getTop(principal) < Entity_getBottom(b);
}

bool Entity_collidedFromLeft(Entity principal, Entity b)
{
    return Entity_collided(principal, b) &&
           Entity_getOldRight(principal) <= Entity_getLeft(b) // was not colliding
           && Entity_getRight(principal) > Entity_getLeft(b);
}

bool Entity_collidedFromRight(Entity principal, Entity b)
{
    return Entity_collided(principal, b) &&
           Entity_getOldLeft(principal) >= Entity_getRight(b) && // was not colliding
           Entity_getLeft(principal) < Entity_getRight(b);
}
