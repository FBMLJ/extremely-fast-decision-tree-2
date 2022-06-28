#include <stdlib.h>
#include "util.h"



CONTROLE_ITEM_LINHA* nova_lista_de_item(){
    CONTROLE_ITEM_LINHA* controle = (CONTROLE_ITEM_LINHA*)malloc(sizeof(CONTROLE_ITEM_LINHA));
    controle->quantidade = 0;
    controle->lista = NULL;
    return controle;
}


void append_linha(CONTROLE_ITEM_LINHA*  controle, int* linha){
    controle->quantidade ++;
    LIST_ITEM_LINHA* novo_item = (LIST_ITEM_LINHA*) malloc(sizeof(LIST_ITEM_LINHA));
    novo_item->label = linha[4];
    novo_item->x_vetor[0] = linha[0];
    novo_item->x_vetor[1] = linha[1];
    novo_item->x_vetor[2] = linha[2];
    novo_item->x_vetor[3] = linha[3];
    
    if (controle->lista == NULL) {
        controle-> lista = novo_item;
        return;
    }
    LIST_ITEM_LINHA* atual = controle->lista;
    while(atual->proximo != NULL) atual = atual-> proximo;
    atual->proximo = novo_item;

    
    // LIST_ITEM_LINHA* lista = controle->lista;
}

