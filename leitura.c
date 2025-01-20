#include "leitura.h"
#include "operacao.h"
#include <stdio.h>
#include <string.h>

void le_estrutura(FILE *arq,*Pilotos,*Equipes,int n){
    int aux=0,i,j,c=0;
    char Saux1[32];
    char Saux2[32]
    for(i=0;i<n;i++){
        fscanf(ENTRADA,"%s %s",Saux1,Saux2);
        strcpy(Saux1,Pilotos[i].nome);
        strcpy(Saux2,Pilotos[i].equipe);
        for(j=0;j<c;j++){
            if(strcmp(Saux2,Equipes[j].nome)==0){
                Endereco[i]=j;
                aux=1;
                break;
            }
        }
        if(aux==0){
            strcpy(Equipes[c],Saux1);
            Endereco[i]=c;
            c++;
        }
        aux=0;
    }
}
