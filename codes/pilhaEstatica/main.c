#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
    Aluno *al, a[4] = {{4,"Andre",9.5,7.8,8.5},
	                 {1,"Ricardo",7.5,8.7,6.8},
	                 {3,"Bianca",9.7,6.7,8.4},
	                 {2,"Ana",5.7,6.1,7.4}};

    Pilha* pi = cria_Pilha();

    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));

    int i;
    for(i=0; i < 4; i++){
        insere_Pilha(pi,a[i]);
        al = consulta_Pilha(pi);
        printf("\nINSERIU: \n##################\n");
        imprime_aluno(al);
    }

    for(i=0; i < 4; i++){
        al=consulta_Pilha(pi);
        remove_Pilha(pi);
        printf("\nREMOVEU: \n##################\n");
        imprime_aluno(al);
    }

    // printf("\n\n\nIMPRIME PILHA\n\n");
    // imprime_Pilha(pi);

    libera_Pilha(pi);

    return 0;
}
