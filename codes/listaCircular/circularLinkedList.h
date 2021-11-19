#ifndef CIRCULARLINKEDLIST_H_INCLUDED
#define CIRCULARLINKEDLIST_H_INCLUDED

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,rec;
}typedef Aluno;

struct elemento{
    Aluno dados;
    struct elemento *prox;
}typedef Elemento;

typedef Elemento* Lista;

void limpa();

Lista* cria_lista();
void libera_lista(Lista* li);
// int insere_lista_final(Lista* li, Aluno al);
int insere_lista_inicio(Lista* li, Aluno al);
int insere_lista_ordenada(Lista* li, Aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
// int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

#endif /* CIRCULARLINKEDLIST_H_INCLUDED */