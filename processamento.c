#include "registros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_partidas(FILE *arq,Estrutura_Pilotos *Pilotos,Estrutura_Equipes *Equipes,int tabela[],int n,int m){
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
                                Equipes[l].pontos+=tabela[j];
                                Equipes[l].colocacao[j]++;
                            }
                        }
                    }
                }
            }
            else{
                for(int k=0;k<n;k++){
                    if(strcmp(Saux,Pilotos[k].nome)==0){
                        Pilotos[k].colocacao[j]++;
                        strcpy(Saux,Pilotos[k].equipe);
                        for(int l=0;l<n/2;l++){
                            if(strcmp(Equipes[l].nome,Saux)==0){
                                Equipes[l].colocacao[j]++;
                            }
                        }
                    }
                }
            }
        }
    }
}