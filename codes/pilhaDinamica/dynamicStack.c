#include <stdio.h>
#include <stdlib.h>
#include "dynamicStack.h" //inclui os Prot�tipos

Pilha* newStack(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;
        pi->qtd=0;
    }
    return pi;
}

void freeStack(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while(pi->topo != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        pi->qtd=0;
        free(pi);
    }
}

Aluno * top(Pilha* pi){
    if(pi == NULL || isEmpty(pi))
        return NULL;
    return &pi->topo->dados;
}

int push(Pilha* pi, Aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = pi->topo;
    pi->topo = no;
    pi->qtd++;
    return 1;
}

int pop(Pilha* pi){
    if(pi == NULL || isEmpty(pi))
        return 0;
    Elem *no = pi->topo;
    pi->topo = no->prox;
    pi->qtd--;
    free(no);
    return 1;
}

int lenght(Pilha* pi){
    if(pi == NULL)
        return 0;
    return pi->qtd;
}

int isFull(Pilha* pi){
    return 0;
}

int isEmpty(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(pi->topo == NULL)
        return 1;
    return 0;
}

void imprime_aluno(Aluno* al){
    if(al == NULL)
        return;
    printf("Matricula: %d\n",al->matricula);
    printf("Nome: %s\n",al->nome);
    printf("Notas: %f %f %f\n",al->n1,
                               al->n2,
                               al->rec);
        printf("-------------------------------\n");
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = pi->topo;
    while(no != NULL){
        imprime_aluno(&no->dados);
        no = no->prox;
    }
}