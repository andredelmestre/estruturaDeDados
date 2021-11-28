#include <stdio.h>
#include <stdlib.h>
#include "staticStack.h"

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

Aluno * consulta_Pilha(Pilha * pi){
    if(pi == NULL || Pilha_vazia(pi))
        return 0;
    return &pi->dados[pi->qtd-1];
}

int insere_Pilha(Pilha* pi, Aluno al){
    if(pi == NULL)
        return 0;
    if(Pilha_cheia(pi))//pilha cheia
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){

    if(pi == NULL || Pilha_vazia(pi))
        return 0;
    pi->qtd--;
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i=pi->qtd-1; i >=0; i--){
        imprime_aluno(&pi->dados[i]);
    }
}

void imprime_aluno(Aluno* al){
    if(al == NULL)
        return;
    printf("Matricula: %d\n",al->matricula);
    printf("Nome: %s\n",al->nome);
    printf("Notas: %f %f %f\n",al->n1,
                               al->n2,
                               al->rec);
    printf("####################################\n");
}
