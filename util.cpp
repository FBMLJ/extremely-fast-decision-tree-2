#include"util.h"
#include<stdlib.h>
#include<stdio.h>
#define NUM_LABEL 3


// ATRIBUTO _criar_instancia_de_atributo(){

// }


ATRIBUTO** criar_instancia_de_atributos(){
    

    ATRIBUTO** vetor = (ATRIBUTO**) malloc(sizeof(ATRIBUTO*)*4);
    for (int i=0;i<4;i++)
        vetor[i] = (ATRIBUTO*)malloc(sizeof(ATRIBUTO));
    vetor[0]->numero_de_valor_distinto = 24;
    int* vetor1 =(int*) malloc(sizeof(int)*24);
    // int vetor1[24] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    for (int i =0;i < 24;i++) vetor1[i] = i;
    vetor[0]->vetor = vetor1;
    return vetor;
}

CONTADOR* novo_contador(ATRIBUTO* at , int pos){
    CONTADOR *novo_contador = (CONTADOR*) malloc(sizeof(CONTADOR));
    novo_contador->atributo = at;
    novo_contador-> pos = pos;
    int quantidade_de_valores = NUM_LABEL*at->numero_de_valor_distinto;
    novo_contador->vetor = (int*) malloc(sizeof(int)*quantidade_de_valores);
    for (int i = 0; i < quantidade_de_valores;i++)novo_contador->vetor[i] = 0;
    novo_contador->tamanho = quantidade_de_valores;
    return novo_contador;
}