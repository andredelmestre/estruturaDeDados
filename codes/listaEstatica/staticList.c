#include <stdio.h>
#include <stdlib.h>
#include "staticList.h"

Lista* cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		li->qtd = 0;
	return li;
}

Lista * libera_lista(Lista* li){
	free(li);
	li = NULL;
	return li;
}

int tamanho_lista(Lista* li){
	if(li == NULL)
		return -1;
	else
		return li->qtd;
}

int lista_cheia(Lista* li){
	if(li == NULL)
		return -1;
	return (li->qtd==MAX);
}

int lista_vazia(Lista* li){
	if(li == NULL)
		return -1;
	return (li->qtd==0);
}

//return 1 in case of success
int insere_lista_final(Lista* li, Aluno al){
	if(li==NULL)
		return 0;
	if(lista_cheia(li))
		return 0;
	li->dados[li->qtd] = al;
	li->qtd++;
	return 1;
}

int remove_lista_final(Lista* li){
	if(li==NULL)
		return 0;
	if(lista_vazia(li))
		return 0;
	li->qtd--;
	return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    printf("-------------------------------\n");
    for(i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %f %f %f\n",li->dados[i].n1,
                                   li->dados[i].n2,
                                   li->dados[i].rec);
        printf("-------------------------------\n");
    }
}

