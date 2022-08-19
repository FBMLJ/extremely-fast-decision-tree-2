typedef struct atributo
{
    int numero_de_valor_distinto;
    int* vetor;
} ATRIBUTO;




typedef struct t_contador{
    int *vetor;
    int tamanho;
    int pos;
    ATRIBUTO *atributo;
} CONTADOR;

typedef struct t_arvore{
    t_arvore **filhos;
    int num_de_filhos;
    int contador_de_elementos;
    t_contador ** contador;
    int id_atributo;


    
} ARVORE;

// ATRIBUTO _criar_instancia_de_atributo();
ATRIBUTO** criar_instancia_de_atributos();
ARVORE* criar_arvore(ATRIBUTO** atributos);

void adiciona_na_arvore(int *vetor, ARVORE* arv, ATRIBUTO** atributos);


CONTADOR* novo_contador(ATRIBUTO* at, int pos );

int predicao(int *vetor, ARVORE * arv, ATRIBUTO ** atributos);
int calcula_memoria(ARVORE *arv,ATRIBUTO** atributos);