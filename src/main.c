#include <stdio.h>
#include <keypadc.h>
#include <stdlib.h>
#include <fileioc.h>
#include <tice.h>

#include "file.h"
#include "graphics.h"
#include "helper.h"


int main(void) {
    FILE* hFile;
    uint16_t curChar;
    bool caps = false;
    char data[1000] = {0};
    char buf[20];
    int sz = 0;

    // fills the screen with white
    fill_screen(COLOR_WHITE);
    // sets cursor at the top left of screen
    os_SetCursorPos(0, 0);

    message_box("test message");

    read_data(data, "file.txt", 0);

    os_PutStrFull(data);

    curChar = os_GetKey();

    while (curChar != KEY_CLEAR) {
        curChar = os_GetKey();

        if (curChar == KEY_Y_EQUALS) {
            save_data("file.txt", data, sz, "a");
            continue;
        }

        

        if (curChar == KEY_WINDOW) {
            clear_file("file.txt");
            continue;
        }

        // check to toggle on caps lock
        if (curChar == KEY_POWER) {
            caps = !caps;
            continue;
        }
        // converts the ti scancode to an ascii char
        curChar = code_to_char((int24_t)curChar, caps);
        
        data[sz] = curChar;
        sz++;
        put_char(curChar);
    }
    return 0;
}

int maina(void)
{
    int i;
// 9
    uint16_t n;
    real_t r;
    char res[20];

    // sets screen to white
    fill_screen(0xFF);
    
    n = os_GetKey();
    r = os_Int24ToReal(n);
    
    os_RealToStr(res, &r, 14, 0, 1);
    os_PutStrFull(res);
    while (!os_GetCSC());
    return 0;
}



void put_char(char c) {
    char buf[2];
    buf[0] = c;
    buf[1] = '\0';
    os_PutStrFull(buf);
}

char code_to_char(int24_t code, bool caps) {
    if (code == KEY_CLEAR) 
        return KEY_CLEAR;

    // dealing with numbers
    if (code >= KEY_ZERO && code <= KEY_NINE) {
        return code - 94;
    }

    // if the code is an operation key (+, -, *, /)
    switch (code) {
    case 128:
        return '+';
    case 129:
        return '-';
    case 130:
        return '*';
    case 131:
        return '/';
    }

    if (!caps)
        return code - 57;
    // return capital letter
    return code - 89;
    
}

