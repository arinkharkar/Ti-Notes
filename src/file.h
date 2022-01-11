#ifndef FILE_H__
#define FILE_H__

#include <stdio.h>

// saves data into the path
void save_data(const char* path, void* data, size_t szData, const char* mode);
// reads file data into buf (if sz is 0, then reads the whole file)
void read_data(void* buf, const char* path, size_t sz);
// clears file (removes all data but keeps as existing file)
void clear_file(const char* path);

// returns size of file based on file handle
static int fsize(FILE* hFile) {
    int sz;
    fseek(hFile, 0, SEEK_END);
    sz = ftell(hFile);
    rewind(hFile);
    return sz;
}

#endif