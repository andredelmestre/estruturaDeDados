#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

#define MAX 10
// TADs
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, rec;
}typedef Aluno;


struct fila{
	int inicio, final, qtd;
	Aluno dados[MAX];
}typedef Fila;

//global vars

//functions prototype
Fila* cria_Fila();
void libera_Fila(Fila* fi);
Aluno * consulta_Fila(Fila* fi);
int insere_Fila(Fila* fi, Aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
void imprime_aluno(Aluno* al);

#endif /* STATICQUEUE_H_INCLUDED */
