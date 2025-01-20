#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "escrita.h"
#include "operacao.h"

typedef struct{
        char nome[32];
        char equipe[32];
        int colocacao[10];
        int pontos;
    }Estrutura_Pilotos;
    typedef struct{
        char *nome;
        int *colocacao;
        int pontos;
    }Estrutura_Equipes;
int main(){
    Estrutura_Pilotos* Pilotos = malloc(sizeof(Estrutura_Pilotos)*n);
}
void le_partidas(FILE *arq,*Pilotos,*Equipes,int tabela[],int n,int m){
    int aux, i,j;
    char Saux[32];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            fscanf(arq,"%s",Saux);
            if(j<10){
                for(int k=0;k<n;k++){
                    if(strcmp(Saux,Pilotos[k].nome)==0){
                        Pilotos[k].pontos+=tabela[j];
                        Pilotos[k].colocacao[j]++;
                        strcpy(Saux,Pilotos[k].equipe);
                        for(int l=0;l<n/2;l++){
                            if(strcmp(Equipes[l].nome,Saux)==0){
                                Pilotos[l].pontos+=tabela[j];
                                Pilotos[l].colocacao[j]++;
                            }
                        }
                    }
                }
            }
        }
    }
}