#include "leitura.h"
#include "registros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_estrutura(FILE *arq,Estrutura_Pilotos *Pilotos,Estrutura_Equipes *Equipes,int n){
    int aux=0,i,j,c=0;
    char Saux1[32];
    char Saux2[32];
    for(i=0;i<n;i++){
        fscanf(arq,"%s %s",Saux1,Saux2);
        strcpy(Pilotos[i].nome,Saux1);
        strcpy(Pilotos[i].equipe,Saux2);
        for(j=0;j<c;j++){
            if(strcmp(Saux2,Equipes[j].nome)==0){
                aux=1;
                break;
            }
        }
        if(aux==0){
            strcpy(Equipes[j].nome,Saux1);
            c++;
        }
        aux=0;
    }
}