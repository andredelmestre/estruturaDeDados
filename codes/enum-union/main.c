#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Semana dia;			//parte 1
    Partido legenda;
    Ideologia lado;

	dia = TER;
    legenda = PDT;
    lado.esquerda=0;
    lado.direita=0;

    printf("-------------------------------\n");
    printf("legenda eh %i\n", legenda);
    printf("dia eh %i\n", dia);
    printf("-------------------------------\n");
    limpa();
    

    printf("-------------------------------\n");
    if(legenda==PDT){
        printf("PDT eh esquerda\n");
        lado.esquerda++;
    }

    legenda = PT;
    if(legenda==PT){
        printf("PT eh esquerda\n");
        lado.esquerda++;
    }
    printf("lado.direita: %i\n", lado.direita);
    printf("-------------------------------\n");
    limpa();

    Macro refeicao;

    refeicao.gordura = 20;
    printf("-------------------------------\n");
    printf("refeicao.gordura: %i\n", refeicao.gordura);
    printf("refeicao.fat: %i\n", refeicao.fat);
    printf("-------------------------------\n");
    limpa();


    printf("-------------------------------\n");
    printf("sizeof(Ideologia) eh %i\n", sizeof(Ideologia));
    printf("sizeof(Macro) eh %i\n", sizeof(Macro));
    printf("-------------------------------\n");


    return 0;
}