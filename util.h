typedef struct atributo
{
    int numero_de_valor_distinto;
    int* vetor;
} ATRIBUTO;




typedef struct contador{
    int *vetor;
    int tamanho;
    int pos;
    ATRIBUTO *atributo;
} CONTADOR;

// ATRIBUTO _criar_instancia_de_atributo();
ATRIBUTO** criar_instancia_de_atributos();

CONTADOR* novo_contador(ATRIBUTO* at, int pos );