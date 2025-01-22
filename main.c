#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
#include "escrita.h"
#include "ordenacao.h"
#include "processamento.h"
#include "registros.h"
int main(int argc,char *argv[]){
  int n,m;
  int tabela[10]={25,18,15,12,10,8,6,4,2,1};
  char aux[32];
  Estrutura_Equipes* Equipes = malloc(sizeof(Estrutura_Equipes)*n);
  Estrutura_Pilotos* Pilotos = malloc(sizeof(Estrutura_Pilotos)*n);
  FILE* arq=fopen(argv[1],"r");
  fscanf(arq,"%d %d",&n,&m);
  //escaneia o numero de jogadores e de partidas
  //tirei os asteriscos da frente de pilotos e equipes
  le_estrutura(arq,Pilotos,Equipes,n);
  fscanf(arq,"%s",aux);
  le_partidas(arq,Pilotos,Equipes,tabela,n,m);
  printf("%d",Pilotos[0].pontos);
  return 0;
}