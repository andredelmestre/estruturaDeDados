#ifndef DYNAMICSTACK_H_INCLUDED
#define DYNAMICSTACK_H_INCLUDED

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, rec;
}typedef Aluno;

//Definição do tipo Pilha
struct elemento{
    Aluno dados;
    struct elemento *prox;
}typedef Elem;

struct pilha{
    int qtd;
    Elem *topo;
}typedef Pilha;

// typedef Elem* Pilha;

Pilha* newStack();
void freeStack(Pilha* pi);
Aluno top(Pilha* pi);
int push(Pilha* pi, Aluno al);
int pop(Pilha* pi);
int lenght(Pilha* pi);
int isFull(Pilha* pi);
int isEmpty(Pilha* pi);
void imprime_aluno(Aluno al);
void imprime_Pilha(Pilha* pi);

#endif /* DYNAMICSTACK_H_INCLUDED */