#include <stdio.h>
#include <stdlib.h>
#include "dynamicQueue.h" //inclui os Protótipos

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

Aluno consulta_Fila(Fila* fi){
    Aluno err = {-1,"",0.0,0.0,0.0};
    if(fi == NULL)
        return err;
    if(fi->inicio == NULL)//fila vazia
        return err;
    return fi->inicio->dados;
}

int insere_Fila(Fila* fi, Aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_aluno(Aluno al){
    if(al.matricula == -1)
        return;
    printf("Matricula: %d\n",al.matricula);
    printf("Nome: %s\n",al.nome);
    printf("Notas: %f %f %f\n",al.n1,
                               al.n2,
                               al.rec);
        printf("-------------------------------\n");
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int tam = tamanho_Fila(fi);
    Aluno al;
    while(tam){
        al = consulta_Fila(fi);
        imprime_aluno(al);
        insere_Fila(fi, al);
        remove_Fila(fi);
        tam--;
    }
}
