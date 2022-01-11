#include <graphx.h>
#include <tice.h>
#include "graphics.h"

void message_box(const char* text) {
    // the main box
    draw_rect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 170, 100, COLOR_BLACK, true);
    
    os_SetCursorPos(3, 7);
    os_PutStrFull(text);   

    // draws the ok box 
    draw_rect(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 25, 60, 20, COLOR_BLACK, true);
    os_SetCursorPos(5, 12);
    os_PutStrFull("OK");

    // waits for key press
    while (!os_GetCSC());

    // clears screen
    fill_screen(COLOR_WHITE);
}

void draw_rect(int _x, int _y, int width, int height, int col, bool outline) {    
    // centers the x and y values

    // each pixel is 2 bytes
    uint16_t* ptr;
    int x, y;

    // centers the given coords
    _x -= width / 2;
    _y -= height / 2;
    ptr = (uint16_t*)gfx_vram + _y * SCREEN_WIDTH + _x;
    if (!outline) {
        for (y = 0; y < height; y++) {
            for (x = 0; x < width; x++) {
                *ptr = col;
                ptr++;
            }
            ptr += SCREEN_WIDTH - width;
        }
    } else {
        draw_horiz(_x, _y, width, col);
        draw_vert(_x, _y, height, col);

        draw_horiz(_x, _y + height, width, col);
        draw_vert(_x + width, _y, height, col);
    }

}

void draw_horiz(int x1, int y1, int len, uint16_t col) {
    uint16_t* ptr = (uint16_t*)gfx_vram + y1 * SCREEN_WIDTH + x1;
    int i;

    for (i = 0; i <= len; i++) {
        *ptr = col;
        ptr++;
    }
}

void draw_vert(int x1, int y1, int len, uint16_t col) {
    uint16_t* ptr = (uint16_t*)gfx_vram + y1 * SCREEN_WIDTH + x1;
    int i;

    for (i = 0; i < len; i++) {
        *ptr = col;
        ptr += SCREEN_WIDTH;
    }
}

// Colors in the entire lcd with the specified color
void fill_screen(uint8_t col) {
    int i = 0;
    
    while (i < 153600) {
        gfx_vram[i] = col;
        i++;
    }
}