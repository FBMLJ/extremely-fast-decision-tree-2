#include<stdio.h>
#include"util.h"
#include<stdlib.h>

int main(){
    
    ATRIBUTO** atributos =  criar_instancia_de_atributos();
    ARVORE* arv = criar_arvore(atributos);
    FILE  *f = fopen("file.csv","r");
    FILE *f1 = fopen("output.csv","w");
    FILE *f2 = fopen("memory_output.csv", "w");
    int *dados = (int*)malloc(sizeof(int)*5);
    for (int i=0; i < 113931;i++){
        int n1,n2,n3,n4,n5;
        fscanf(f,"%d,%d,%d,%d,%d\n", &n1,&n2,&n3,&n4,&n5);
        dados[0] = n1;
        dados[1] = n2;
        dados[2] = n3;
        dados[3] = n4;
        dados[4] = n5;
        int predict = predicao(dados,arv,atributos);
        adiciona_na_arvore(dados, arv,atributos    );
        fprintf( f2,"%d,%d\n",i, calcula_memoria(arv,atributos));
        fprintf(f1,"%d,%d\n", predict, dados[4]);

    }

    free(dados);
    fclose(f);
    fclose(f2);
    fclose(f1);
    FILE  *f_ = fopen("file.csv","r");
    FILE *f3 = fopen("acuracia_final.csv", "w");
    for (int i=0; i < 113931;i++){
        int n1,n2,n3,n4,n5;
        fscanf(f_,"%d,%d,%d,%d,%d\n", &n1,&n2,&n3,&n4,&n5);
        dados[0] = n1;
        dados[1] = n2;
        dados[2] = n3;
        dados[3] = n4;
        dados[4] = n5;
        int predict = predicao(dados,arv,atributos);
        fprintf(f3,"%d,%d\n", predict, dados[4]);
        

    }
    fclose(f3);


}