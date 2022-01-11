#ifndef HELPER_H
#define HELPER_H
#include <stdio.h>

#define KEY_CLEAR      9
#define KEY_MATH       50
#define KEY_POWER      132
#define KEY_ZERO       142
#define KEY_NINE       151
#define KEY_Y_EQUALS   73
#define KEY_WINDOW     72




void fill_screen(uint8_t col);
void put_char(char c);
char code_to_char(int24_t code, bool caps);




#endif