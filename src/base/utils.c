#include <genesis.h>
#include "utils.h"

void Utils_showCenteredText(char s[], int posYInTiles)
{
    VDP_drawText(s, 20 - strlen(s) / 2, posYInTiles);
}


void Utils_resetScreen()
{
    if (SPR_isInitialized())
    {
        SPR_clear();
        SPR_reset();
        SPR_update();
    }
    VDP_clearTextArea(0, 0, 320 / 8, 224 / 8);
    VDP_clearPlane(BG_A, FALSE);
    VDP_clearPlane(BG_B, FALSE);
    VDP_clearPlane(WINDOW, FALSE);
}

int Utils_getButtonCode(u16 changed)
{

    if (changed & BUTTON_UP)
        return BUTTON_UP;
    if (changed & BUTTON_DOWN)
        return BUTTON_DOWN;
    if (changed & BUTTON_LEFT)
        return BUTTON_LEFT;
    if (changed & BUTTON_RIGHT)
        return BUTTON_RIGHT;
    if (changed & BUTTON_A)
        return BUTTON_A;
    if (changed & BUTTON_B)
        return BUTTON_B;
    if (changed & BUTTON_C)
        return BUTTON_C;
    if (changed & BUTTON_START)
        return BUTTON_START;
    if (changed & BUTTON_X)
        return BUTTON_X;
    if (changed & BUTTON_Y)
        return BUTTON_Y;
    if (changed & BUTTON_Z)
        return BUTTON_Z;
    if (changed & BUTTON_MODE)
        return BUTTON_MODE;
    if (changed & BUTTON_DIR)
        return BUTTON_DIR;
    if (changed & BUTTON_BTN)
        return BUTTON_BTN;
    if (changed & BUTTON_ALL)
        return BUTTON_ALL;

    return -1;
}


const char * Utils_getButtonName(int buttonCode)
{

    char * buffer = (char *)malloc(sizeof(char) * 100);

    switch (buttonCode)
    {

    case BUTTON_UP:
        strcpy(buffer, "BUTTON_UP");
        break;
    case BUTTON_DOWN:
        strcpy(buffer, "BUTTON_DOWN");
        break;
    case BUTTON_LEFT:
        strcpy(buffer, "BUTTON_LEFT");
        break;
    case BUTTON_RIGHT:
        strcpy(buffer, "BUTTON_RIGH");
        break;
    case BUTTON_A:
        strcpy(buffer, "BUTTON_A");
        break;
    case BUTTON_B:
        strcpy(buffer, "BUTTON_B");
        break;
    case BUTTON_C:
        strcpy(buffer, "BUTTON_C");
        break;
    case BUTTON_START:
        strcpy(buffer, "BUTTON_STAR");
        break;
    case BUTTON_X:
        strcpy(buffer, "BUTTON_X");
        break;
    case BUTTON_Y:
        strcpy(buffer, "BUTTON_Y");
        break;
    case BUTTON_Z:
        strcpy(buffer, "BUTTON_Z");
        break;
    case BUTTON_MODE:
        strcpy(buffer, "BUTTON_MODE");
        break;
    case BUTTON_DIR:
        strcpy(buffer, "BUTTON_DIR");
        break;
    case BUTTON_BTN:
        strcpy(buffer, "BUTTON_BTN");
        break;
    case BUTTON_ALL:
        strcpy(buffer, "BUTTON_ALL");
        break;

    default:
        strcpy(buffer, "UNKNOWN");
        break;
    }

    return (const char *)buffer;
}

void Utils_showFormattedText(char *format, int posXInTiles, int posYInTiles, ...)
{
    va_list aptr;
    char buffer[100];
    int ret;
    va_start(aptr, posYInTiles);
    ret = vsprintf(buffer, format, aptr);
    va_end(aptr);
    VDP_drawText(buffer, posXInTiles, posYInTiles);
}

int Utils_sign(int x)
{
    //-1 for negative, 1 for positive and 0 for 0
    return (x > 0) - (x < 0);
}

int Utils_randomInt(int min, int max)
{

    int rnd = random() % (max - min + 1) + min;
    return rnd;
}

Vect2D_f16 Utils_reflect(Vect2D_f16 vector, Vect2D_f16 normal)
{
    Vect2D_f16 result;
    fix16 val = fix16Mul(FIX16(2.0f), fix16Add(fix16Mul(vector.x, normal.x), fix16Mul(vector.y, normal.y)));
    result.x = fix16Sub(vector.x, fix16Mul(normal.x, val));
    result.y = fix16Sub(vector.y, fix16Mul(normal.y, val));
    return result;
}
