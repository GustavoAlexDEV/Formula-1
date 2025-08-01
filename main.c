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
  FILE* arq1=fopen(argv[1],"r");
  FILE* arq2=fopen(argv[2],"w");
  //escaneia o numero de pilotos e de partidas
  fscanf(arq1,"%d %d",&n,&m);
  Estrutura_Equipes* Equipes = malloc(sizeof(Estrutura_Equipes)*n);
  Estrutura_Pilotos* Pilotos = malloc(sizeof(Estrutura_Pilotos)*n);
  le_estrutura(arq1,Pilotos,Equipes,n);
  //le ---
  fscanf(arq1,"%s",aux);
  //le n pilotos m vezes
  le_partidas(arq1,Pilotos,Equipes,tabela,n,m);
  //ordena os n pilotos
  calcula_resultado(Pilotos,Equipes,n);
  //salva o resultado no arquivo endereçado em arq2
  escrever_resultados(arq2,Pilotos,Equipes,n);
  return 0;
}
