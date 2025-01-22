#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "registros.h"

void calcula_resultado(Estrutura_Pilotos *Pilotos,Estrutura_Equipes *Equipes,int n){
    int i,j,k,l,aux;
    char Saux[32];
    //o primeiro for vai ordenar os valores dos pontos dos pilotos
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            //o if realiza um bubble sort caso a pontuação do piloto i for maior do que a do piloto j
            if(Pilotos[i].pontos<Pilotos[j].pontos){
                //troca dos pontos
                aux=Pilotos[i].pontos;
                Pilotos[i].pontos=Pilotos[j].pontos;
                Pilotos[j].pontos=aux;
                //troca dos nomes
                strcpy(Saux,Pilotos[i].nome);
                strcpy(Pilotos[i].nome,Pilotos[j].nome);
                strcpy(Pilotos[j].nome,Saux);
                //troca das equipes
                strcpy(Saux,Pilotos[i].equipe);
                strcpy(Pilotos[i].equipe,Pilotos[j].equipe);
                strcpy(Pilotos[j].equipe,Saux);
                //troca do critério de desempate
                for(k=0;k<40;k++){
                    aux=Pilotos[i].colocacao[k];
                    Pilotos[i].colocacao[k]=Pilotos[j].colocacao[k];
                    Pilotos[j].colocacao[k]=aux;
                }
            }
        }
    }
    //o segundo for verifica o criterio de desempate dos pilotos
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(Pilotos[i].pontos==Pilotos[j].pontos){
                for(k=0;k<n;k++){
                    //o if vai para outro if caso a classificação k mais alta achada nos dois não se repita
                    if(Pilotos[i].colocacao[k]!=Pilotos[j].colocacao[k]){
                        //o if realiza um bubble sort caso o piloto i tenha mais k-ésimas classificações do que o piloto j
                        if(Pilotos[i].colocacao[k]<Pilotos[j].colocacao[k]){
                            //troca dos nomes
                            strcpy(Saux,Pilotos[i].nome);
                            strcpy(Pilotos[i].nome,Pilotos[j].nome);
                            strcpy(Pilotos[j].nome,Saux);
                            //troca das equipes
                            strcpy(Saux,Pilotos[i].equipe);
                            strcpy(Pilotos[i].equipe,Pilotos[j].equipe);
                            strcpy(Pilotos[j].equipe,Saux);
                            //troca dos critérios de desempate
                            for(l=0;l<40;l++){
                                aux=Pilotos[i].colocacao[l];
                                Pilotos[i].colocacao[l]=Pilotos[j].colocacao[l];
                                Pilotos[j].colocacao[l]=aux;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    //o terceiro for vai ordenar os valores dos pontos das equipes
    for(i=0;i<(n/2)-1;i++){
        for(j=i+1;j<(n/2);j++){
            if(Equipes[i].pontos<Equipes[j].pontos){
                //troca dos pontos
                aux=Equipes[i].pontos;
                Equipes[i].pontos=Equipes[j].pontos;
                Equipes[j].pontos=aux;
                //troca dos nomes
                strcpy(Saux,Equipes[i].nome);
                strcpy(Equipes[i].nome,Equipes[j].nome);
                strcpy(Equipes[j].nome,Saux);
                //troca dos critérios de desempate
                for(k=0;k<40;k++){
                    aux=Equipes[i].colocacao[k];
                    Equipes[i].colocacao[k]=Equipes[j].colocacao[k];
                    Equipes[j].colocacao[k]=aux;
                }
            }
        }
    }
    //o quarto for verifica o criterio de desempate das equipes
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(Equipes[i].pontos==Equipes[j].pontos){
                for(k=0;k<n;k++){
                    //o if vai para outro if caso a classificação k mais alta achada nos dois não se repita
                    if(Equipes[i].colocacao[k]!=Equipes[j].colocacao[k]){
                        //o if realiza um bubble sort caso a equipe i tenha mais k-ésimas classificações do que a equipe j
                        if(Equipes[i].colocacao[k]<Equipes[j].colocacao[k]){
                            //troca dos nomes
                            strcpy(Saux,Equipes[i].nome);
                            strcpy(Equipes[i].nome,Equipes[j].nome);
                            strcpy(Equipes[j].nome,Saux);
                            //troca dos critérios de desempate
                            for(l=0;l<40;l++){
                                aux=Equipes[i].colocacao[l];
                                Equipes[i].colocacao[l]=Equipes[j].colocacao[l];
                                Equipes[j].colocacao[l]=aux;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}
//PS.: Não sabia que dava para fazer bubblesort direto entre estruturas então fiz individualmente cada elemento. Pelo menos funciona