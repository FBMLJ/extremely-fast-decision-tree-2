
typedef struct lista_encadeada_linha {
    int x_vetor[4];
    int label;
    lista_encadeada_linha* proximo;
} LIST_ITEM_LINHA;

typedef struct controle_de_lista_linha {
    int  quantidade ;
    LIST_ITEM_LINHA* lista;
} CONTROLE_ITEM_LINHA;

CONTROLE_ITEM_LINHA* nova_lista_de_item();


void append_linha(CONTROLE_ITEM_LINHA*  lista, int* linha);