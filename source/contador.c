// "Copyright [2018] <Guilherme Rodrigues Lodron Pires>"
#include <stdio.h>
#include <stdlib.h>
#include "contador.hpp"

int total_linhas(FILE* ptr) {
    int linhas = 0;
    char c;
    c = fgetc(ptr);
    if (c == EOF)
        return 0;
    fseek(ptr, -1, 1);
    while (!feof(ptr)) {
        c = fgetc(ptr);
        if (c == '\n') {
            linhas++;
        }  // end if()
    }  // end while()
    return linhas + 1;
}  // end total_linhas()

