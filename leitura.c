#include "leitura.h"
#include "operacao.h"
#include <stdio.h>
#include <string.h>

void le_matrizes(char Pilotos[][],char Equipes[][],int n,int Endereco[]){
    int aux=0,i,j,c=0;
    char Saux1[32];
    for(i=0;i<n;i++){
        fscanf(ENTRADA,"%s %s",Pilotos[i],Saux1);
        for(j=0;j<c;j++){
            if(strcmp(Saux1,Equipes[j])==0){
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