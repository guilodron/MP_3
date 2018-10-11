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

int linhas_em_branco(FILE* ptr) {
    char c;
    int linhas_em_branco = 0;
    c = fgetc(ptr);
    if (c == EOF)
        return 0;
    fseek(ptr, -1, 1);
    while (!feof(ptr)) {
        c = fgetc(ptr);
        if (c == '\n') {
            c = fgetc(ptr);
            if (c == '\n') {
                linhas_em_branco++;
                fseek(ptr, -1, 1);
            }  // end if
        }  // end if
    }  // end while
    return linhas_em_branco + 2;
}  // end linhas_em_branco()

int linhas_comentadas(FILE* ptr) {
    char c;
    int linhas_comentadas = 0;
    while (!feof(ptr)) {
        c = fgetc(ptr);
        if (c == '/') {
            c = fgetc(ptr);
            if (c  == '/') {
                linhas_comentadas++;
            }
            if (c == '*') {
                c = fgetc(ptr);
                while (c != '*') {
                    if (c == '\n')
                        linhas_comentadas++;
                    c = fgetc(ptr);
                }  // end while
            linhas_comentadas++;
            }  // end if
        }  // end if
    }  // end while()
    return linhas_comentadas;
}  // end linhas_comentadas()

int num_linhas(FILE* ptr) {
    int comentadas = linhas_comentadas(ptr);
    rewind(ptr);
    int total = total_linhas(ptr);
    rewind(ptr);
    int brancas = linhas_em_branco(ptr);
    return total - brancas - comentadas;
}  // end num_linhas()

