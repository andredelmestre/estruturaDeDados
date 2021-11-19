#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"

void limpa(){
    getchar();
    system("cls|clear");
}

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elemento *aux, *nodo = *li;
        while((*li) != nodo->prox){
            aux = nodo;
            nodo = nodo->prox;
            free(aux);
        }
        free(nodo);
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || lista_vazia(li))
        return 0;
    int cont = 0;
    Elemento* nodo = *li;
    do{
        cont++;
        nodo = nodo->prox;
    }while(nodo != (*li));
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    if((*li) == (*li)->prox){//lista tem um elemento
        free(*li);
        *li = NULL;
        return 1;
    }
    Elemento *atual = *li;
    while(atual->prox != (*li))//procura o último
        atual = atual->prox;

    Elemento *nodo = *li;
    atual->prox = nodo->prox;
    *li = nodo->prox;
    free(nodo);
    return 1;
}

int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento *nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    if(lista_vazia(li)){//lista vazia: insere início
        *li = nodo;
        nodo->prox = nodo;
    }else{
        Elemento *atual = *li;
        while(atual->prox != (*li)){
            atual = atual->prox;
        }
        atual->prox = nodo;
        nodo->prox = *li;
        *li = nodo;
    }
    return 1;
}


int insere_lista_ordenada(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento *nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    if(lista_vazia(li)){//insere início
        *li = nodo;
        nodo->prox = nodo;
        return 1;
    }
    else{
        if((*li)->dados.matricula > al.matricula){//insere início
            // Elemento *atual = *li;
            // while(atual->prox != (*li))//procura o último
            //     atual = atual->prox;
            // nodo->prox = *li;
            // atual->prox = nodo;
            // *li = nodo;
            return insere_lista_inicio(li, al);
        }
        Elemento *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = nodo;
        nodo->prox = atual;
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))//lista vazia
        return 0;
    Elemento *nodo = *li;
    if(nodo->dados.matricula == mat){//remover do início
        if(nodo == nodo->prox){//lista fica vazia
            free(nodo);
            *li = NULL;
            return 1;
        }else{
            Elemento *ult = *li;
            while(ult->prox != (*li))//procura o último
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(nodo);
            return 1;
        }
    }
    Elemento *ant = nodo;
    nodo = nodo->prox;
    while(nodo != (*li) && nodo->dados.matricula != mat){
        ant = nodo;
        nodo = nodo->prox;
    }
    if(nodo == *li)//não encontrado
        return 0;

    ant->prox = nodo->prox;
    free(nodo);
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL || lista_vazia(li))
        return;
    Elemento* nodo = *li;
    do{
        printf("Matricula: %d\n",nodo->dados.matricula);
        printf("Nome: %s\n",nodo->dados.nome);
        printf("Notas: %f %f %f\n",nodo->dados.n1,
                                   nodo->dados.n2,
                                   nodo->dados.rec);
        printf("-------------------------------\n");
        nodo = nodo->prox;
    }while(nodo != (*li));
}
