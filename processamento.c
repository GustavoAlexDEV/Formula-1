#include "registros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_partidas(FILE *arq,Estrutura_Pilotos *Pilotos,Estrutura_Equipes *Equipes,int tabela[],int n,int m){
    int i,j;
    char Saux[32];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            //recebe uma string do arquivo, na maioria das vezes é o nome do piloto, mas pode receber ---
            fscanf(arq,"%s",Saux);
            //para não atrapalhar na contagem, quando Saux recebe ---, diminui j em 1 e continua 
            if(strcmp(Saux,"---")==0){
                j--;
                continue;
            }
            //se for entre os 10 colocados, aumenta a contagem da pontuação
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
                        break;
                    }
                }
            }
            //se não, só adiciona na classificação para caso precise no desempate, apesar de ser raro o empate até a quadragésima
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
                        break;
                    }
                }
            }
        }
    }
    
}