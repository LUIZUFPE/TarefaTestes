#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 0;

    FILE *f = fopen(argv[1], "rb");
    if (!f) return 0;

    char buf[4];
    fread(buf, 1, 100, f); 
    fclose(f);

    return 0;
}
