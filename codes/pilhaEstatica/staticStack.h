#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_INCLUDED

#define MAX 10
// TADs
struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, rec;
}typedef Aluno;

struct pilha{
	int qtd;	//topo
	Aluno dados[MAX];
}typedef Pilha;

//global vars

//functions prototype
Pilha * cria_Pilha();
void libera_Pilha(Pilha* pi);
Aluno * consulta_Pilha(Pilha * pi);			//TOP
int insere_Pilha(Pilha * pi, Aluno al);		//PUSH
int remove_Pilha(Pilha * pi);				//POP
int tamanho_Pilha(Pilha * pi);
int Pilha_vazia(Pilha * pi);
int Pilha_cheia(Pilha * pi);
void imprime_Pilha(Pilha * pi);
void imprime_aluno(Aluno* al);




// void ordena_pilha(Pilha * pi);
void remove_aluno(Pilha* pi, int matricula);
Pilha * ordena_pilha_2(Pilha * pi);
Pilha * ordena_pilha_aula(Pilha * pi);

#endif /* STATICSTACK_H_INCLUDED */
