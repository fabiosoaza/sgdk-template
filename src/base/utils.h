#ifndef _UTILS_H_
#define _UTILS_H_

#include <genesis.h>

#define ARRAY_COUNT(arrayToCount)\
    sizeof(arrayToCount) / sizeof(arrayToCount[0])\


void Utils_showCenteredText(char s[], int posYInTiles);
void Utils_resetScreen();
void Utils_showFormattedText(char *format, int posXInTiles, int posYInTiles, ...);
int Utils_sign(int x);
int Utils_randomInt(int min, int max);
Vect2D_f16 Utils_reflect(Vect2D_f16 vector, Vect2D_f16 normal);
const char * Utils_getButtonName(int buttonCode);
int Utils_getButtonCode(u16 changed);

int Utils_dumpStruct(void *myStruct, long size);


#endif // _UTILS_H_