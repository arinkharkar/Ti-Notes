#include <stdio.h>
#include "file.h"

void save_data(const char* path, void* data, size_t szData, const char* mode) {
    FILE* hFile;
    // open file with whatever is requested
    hFile = fopen(path, mode);

    // NO MEMORY SAFETY, need to check for null pointers
    if (!hFile) {
        os_PutStrFull("ERROR: FAILED TO OPEN FILE");
        exit(-1);
    }

    fwrite(data, szData, 1, hFile);

    fclose(hFile);

}

void read_data(void* buf, const char* path, size_t sz) {
    FILE* hFile = fopen(path, "r");

    // if size is 0, then read the whole file
    if (!sz) {
        sz = fsize(hFile);
    }

    fread(buf, sz, 1, hFile);

    fclose(hFile);
}

void clear_file(const char* path) {
    fclose(fopen(path, "w"));

}