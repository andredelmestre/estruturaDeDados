#ifndef STATICLIST_H_INCLUDED
#define STATICLIST_H_INCLUDED

#define MAX 10
// TADs
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, rec;
}typedef Aluno;


struct lista{
	int qtd;
	Aluno dados[MAX];
}typedef Lista;

//global vars
Lista *li;

//functions prototype
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_final(Lista* li, Aluno al);
int remove_lista_final(Lista* li);
void imprime_lista(Lista* li);

#endif /* STATICLIST_H_INCLUDED */
