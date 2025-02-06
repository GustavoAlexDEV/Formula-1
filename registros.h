
#ifndef REGISTROS_H
#define REGISTROS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nome[32];
        char equipe[32];
        int colocacao[40];
        int pontos;
    }Estrutura_Pilotos;
typedef struct{
        char nome[32];
        int colocacao[40];
        int pontos;
    }Estrutura_Equipes;

#endif
