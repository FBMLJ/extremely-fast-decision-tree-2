#include"util.h"
#include<stdlib.h>
#include<math.h>
#define NUMERO_ATRIBUTO 4
#define NUM_LABEL 3
#define DELTA 0.2


// criando os atributos
ATRIBUTO** criar_instancia_de_atributos(){
    

    ATRIBUTO** vetor = (ATRIBUTO**) malloc(sizeof(ATRIBUTO*)*NUMERO_ATRIBUTO);
    for (int i=0;i<NUMERO_ATRIBUTO;i++)
        vetor[i] = (ATRIBUTO*)malloc(sizeof(ATRIBUTO));
    // hora
    vetor[0]->numero_de_valor_distinto = 24;
    int* vetor1 =(int*) malloc(sizeof(int)*24);
    for (int i =0;i < 24;i++) vetor1[i] = i;
    vetor[0]->vetor = vetor1;
    // mes
    vetor[1]->numero_de_valor_distinto = 12;
    int* vetor2 =(int*) malloc(sizeof(int)*12);
    for (int i =0;i < 12;i++) vetor2[i] = i+1;
    vetor[1]->vetor = vetor2;

    // semana
    vetor[2]->numero_de_valor_distinto = 7;
    int* vetor3 =(int*) malloc(sizeof(int)*7);
    for (int i =0;i < 7;i++) vetor3[i] = i;
    vetor[2]->vetor = vetor3;

    
    // ano
    vetor[3]->numero_de_valor_distinto = 14;
    int* vetor4 =(int*) malloc(sizeof(int)*14);
    for (int i =0;i < 14;i++) vetor4[i] = 2004+i;
    vetor[3]->vetor = vetor4;


    // // label
    // vetor[4]->numero_de_valor_distinto = NUM_LABEL;
    // int* vetor5 =(int*) malloc(sizeof(int)*NUM_LABEL);
    // for (int i =0;i < NUM_LABEL;i++) vetor5[i] = i;
    // vetor[4]->vetor = vetor5;

    return vetor;
}

// criando contador
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

// criando a arvore
ARVORE* criar_arvore(ATRIBUTO** atributos){
    ARVORE* a = (ARVORE*) malloc(sizeof(ARVORE));
    a->num_de_filhos = 0;
    a->contador_de_elementos = 0;
    a->id_atributo = -1;
    a->contador = (CONTADOR**) malloc(sizeof(CONTADOR*)*NUMERO_ATRIBUTO+1);
    for (int i= 0; i < NUMERO_ATRIBUTO;i++)  a->contador[i] = novo_contador(atributos[i], i);
    
    return a;
}
int find_id(int valor, ATRIBUTO* at){
    for(int i = 0; i < at->numero_de_valor_distinto;i++){
        if (at->vetor[i] == valor)
            return i;
    }
    
    return -1;
}

void adiciona_no_contador(int id,int label, CONTADOR* contador, ATRIBUTO* at){
    contador->vetor[ at->numero_de_valor_distinto*label + id] ++;
    // printf("%d  \n", contador->vetor[ at->numero_de_valor_distinto*label + id]);

}


float calcula_information_gain(CONTADOR* contador, ATRIBUTO* atr){
    int maximo = 0;
    for (int i=0;i < contador->tamanho;i++)
        maximo = maximo +contador->vetor[i];
    // printf("%d  ",maximo);
    float information_gain = 0;
    for (int atr_id=0;atr_id < atr->numero_de_valor_distinto;atr_id++){
        float temp = 0;
        int max_local = 0;
        for (int label_id=0; label_id < NUM_LABEL; label_id++){
            max_local+=  contador->vetor[label_id*atr->numero_de_valor_distinto + atr_id];
        }
    
        if ((max_local) == 0) break;
        for (int label_id=0; label_id < NUM_LABEL; label_id++){
            float prob = ((float)contador->vetor[label_id*atr->numero_de_valor_distinto + atr_id])/max_local;
            // printf("%f  ", prob);
            if (prob == 0) continue;
           
            temp += prob*log2(prob);
            
        }

        
        information_gain -=((float)max_local/maximo)* temp ;
    }
    // printf("  ");
    if (information_gain ==0){
        return -1;
    }
    // printf("%f   ", information_gain);
    information_gain = 1-information_gain;
    // printf("%f\n", information_gain);
    return information_gain;   
}
float calcula_limite(int n){
    return sqrt(log(1/DELTA)/(2*n));
}
void adiciona_na_arvore(int *vetor, ARVORE* arv, ATRIBUTO **atributos){
    // caso não seja folha
    while(arv->id_atributo != -1){
        int id_do_filho = find_id(vetor[arv->id_atributo], atributos[arv->id_atributo]) ;
        
        arv = arv->filhos[id_do_filho];
        
    }
    arv->contador_de_elementos ++;
    // adicionando elemento no contador
    int label = vetor[NUMERO_ATRIBUTO];
    for( int atributo_atual= 0; atributo_atual < NUMERO_ATRIBUTO; atributo_atual++ ){
        int valor = vetor[atributo_atual];
        int id = find_id(valor, atributos[atributo_atual]);
        adiciona_no_contador(id,label, arv->contador[atributo_atual], atributos[atributo_atual]);
        
    }

    float maior1 = -1, maior2 = -1;
    int id1=-1,id2=-1;
    for( int atributo_atual= 0; atributo_atual < NUMERO_ATRIBUTO; atributo_atual++ ){
        float temp = calcula_information_gain(arv->contador[atributo_atual], atributos[atributo_atual]);
        if (temp > maior1) {
            maior2 = maior1;
            id2 = id1;
            maior1 = temp;
            id1 = atributo_atual;
        } else if (temp>maior2){
            maior2 = temp;
            id2 = atributo_atual;
        }

    }
    float dif = maior1 -maior2;
    if (dif != 0 && dif> calcula_limite(arv->contador_de_elementos) && (id2 !=-1)){
        // divisão aqui
        
        arv->id_atributo = id1;
        arv->filhos =(ARVORE**) malloc(sizeof(ARVORE*) * atributos[id1]->numero_de_valor_distinto);
        for(int i=0; i < NUMERO_ATRIBUTO;i++) 
            free(arv->contador[i]) ;
                
        for (int i=0; i< atributos[id1]->numero_de_valor_distinto;i++ ){
            arv->filhos[i] = criar_arvore(atributos);
        }
        

    }
    

    return;
}