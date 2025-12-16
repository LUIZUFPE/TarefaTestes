#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[8];

    if (!fgets(buf, sizeof(buf), stdin)) {
        return 0;
    }

    if (buf[0] == 'A') {
        puts("Path A");

        if (buf[1] == '1') puts("Path A1");
        if (buf[1] == '2') puts("Path A2");
    }

    if (buf[0] == 'B') {
        puts("Path B");
    }

    if (buf[0] == 'C' && buf[1] == '3') {
        puts("Path C3");
    }

    return 0;
}
