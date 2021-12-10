#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
int main(){
    Aluno al, a[4] = {{4,"Andre",9.5,7.8,8.5},
                     {1,"Ricardo",7.5,8.7,6.8},
                     {3,"Bianca",9.7,6.7,8.4},
                     {2,"Ana",5.7,6.1,7.4}};

    Pilha* pi = newStack();

    printf("Tamanho: %d\n\n\n\n",lenght(pi));

    int i;
    for(i=0; i < 4; i++){
        push(pi,a[i]);
        al = top(pi);
        printf("\nINSERIU: \n##################\n");
        imprime_aluno(al);
    }

    printf("\n\n\nIMPRIME PILHA\n\n");
    imprime_Pilha(pi);

    for(i=0; i < 4; i++){
        pop(pi);
        al = top(pi);
        printf("\nREMOVEU: \n##################\n");
        imprime_aluno(al);
        // imprime_Pilha(pi);
    }

    printf("\n\n\nIMPRIME PILHA\n\n");
    imprime_Pilha(pi);

    freeStack(pi);

    return 0;
}

