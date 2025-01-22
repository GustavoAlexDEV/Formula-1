#include "leitura.h"
#include "registros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void escrever_resultados(FILE *arq,Estrutura_Pilotos *Pilotos, Estrutura_Equipes *Equipes,int n){
    //o primeiro for escreve a colocação, o nome do piloto, pontos dele, quantas partidas ele venceu e quantos lugares ele ja teve no pódio
    for(int i=0;i<n;i++){
        int podio=Pilotos[i].colocacao[0]+Pilotos[i].colocacao[1]+Pilotos[i].colocacao[2];
        fprintf(arq,"%d %s %d %d %d\n",i+1,Pilotos[i].nome,Pilotos[i].pontos,Pilotos[i].colocacao[0],podio);  
    }
    fprintf(arq,"---\n");
    //o segundo for escreve a colocação, o nome da equipe e quantos pontos ela acumulou
    for(int i=0;i<n/2;i++){
        fprintf(arq,"%d %s %d \n",i+1,Equipes[i].nome,Equipes[i].pontos);  
    }
    fprintf(arq,"---");
}