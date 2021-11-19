#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkedList.h" 

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
    if(li != NULL){
        Elemento* nodo;
        while(!lista_vazia(li)){
            nodo = *li;
            *li = (*li)->prox;
            free(nodo);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || lista_vazia(li))
        return 0;
    int cont = 0;
    Elemento* nodo = *li;
    while(nodo != NULL){
        cont++;
        nodo = nodo->prox;
    }
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
    if(lista_vazia(li))
        return 0;
    Elemento *nodo = *li;
    *li = nodo->prox;
    if(nodo->prox != NULL)
        nodo->prox->ant = NULL;
    free(nodo);
    return 1;
}

int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento* nodo;
    nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    nodo->prox = (*li);
    nodo->ant = NULL;
    if(!lista_vazia(li))//lista não vazia: apontar para o anterior!
        (*li)->ant = nodo;
    *li = nodo;
    return 1;
}






int insere_lista_ordenada(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento *nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    if(lista_vazia(li)){//lista vazia: insere início
        nodo->prox = NULL;
        nodo->ant = NULL;
        *li = nodo;
        return 1;
    }
    else{
        Elemento *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            nodo->ant = NULL;
            (*li)->ant = nodo;
            nodo->prox = (*li);
            *li = nodo;
        }else{
            nodo->prox = ante->prox;
            nodo->ant = ante;
            ante->prox = nodo;
            if(atual != NULL)
                atual->ant = nodo;
        }
        return 1;
    }
}

int insere_lista_final(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento *nodo;
    nodo = (Elemento*) malloc(sizeof(Elemento));
    if(nodo == NULL)
        return 0;
    nodo->dados = al;
    nodo->prox = NULL;
    if(lista_vazia(li)){//lista vazia: insere início
        nodo->ant = NULL;
        *li = nodo;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = nodo;
        nodo->ant = aux;
    }
    return 1;
}

int remove_lista(Lista* li, int mat){//TERMINAR
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;
    Elemento *nodo = *li;
    while(nodo != NULL && nodo->dados.matricula != mat){
        nodo = nodo->prox;
    }
    if(nodo == NULL)//não encontrado
        return 0;

    if(nodo->ant == NULL)//remover o primeiro?
        *li = nodo->prox;
    else
        nodo->ant->prox = nodo->prox;

    if(nodo->prox != NULL)//não é o último?
        nodo->prox->ant = nodo->ant;

    free(nodo);
    return 1;
}


int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))//lista vazia
        return 0;

    Elemento *nodo = *li;
    while(nodo->prox != NULL)
        nodo = nodo->prox;

    if(nodo->ant == NULL)//remover o primeiro e único
        *li = nodo->prox;
    else
        nodo->ant->prox = NULL;

    free(nodo);
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* nodo = *li;
    while(nodo != NULL){
        printf("Matricula: %d\n",nodo->dados.matricula);
        printf("Nome: %s\n",nodo->dados.nome);
        printf("Notas: %f %f %f\n",nodo->dados.n1,
                                   nodo->dados.n2,
                                   nodo->dados.rec);
        printf("-------------------------------\n");

        nodo = nodo->prox;
    }
}
