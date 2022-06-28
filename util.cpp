#include <stdlib.h>
#include "util.h"


CONTROLE_ITEM_LINHA* nova_lista_de_item(){
    CONTROLE_ITEM_LINHA* lista = (CONTROLE_ITEM_LINHA*)malloc(sizeof(CONTROLE_ITEM_LINHA));
    lista->quantidade = 0;
    return lista;
}



