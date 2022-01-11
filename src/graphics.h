#ifndef GRAPHICS_H
#define GRAPHICS_H

#define SCREEN_WIDTH   320
#define SCREEN_HEIGHT  240


#define COLOR_WHITE 0xFF
#define COLOR_BLACK 0x00


void message_box(const char* text);
void draw_rect(int _x, int _y, int width, int height, int col, bool outline);
void draw_horiz(int x1, int y1, int len, uint16_t col);
void draw_vert(int x1, int y1, int len, uint16_t col);

void fill_screen(uint8_t col);
static enum layout_type {
    LAYOUT_CENTER,
    LAYOUT_LEFT
};

#endif
