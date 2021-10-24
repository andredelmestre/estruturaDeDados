#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define MAX 10
// TADs
struct aluno{
	int matricula;
	char status, nome[50];
	float n1, n2, rec;
}typedef Aluno;


//variaveis globais

//funcoes auxiliares
void limpa();
float maior(float a, float b);
//funcoes parte 2
void imprime_aluno(Aluno* al);
void le_aluno(Aluno* al, int matricula);

//funcoes parte 3
void inicializa_aluno(Aluno* al, int matricula);
float media_aluno(Aluno * al);

//funcoes parte 4
float media_turma(Aluno * turma, int tamanho);
int conta_status(Aluno * turma, int tamanho, char status);
Aluno * consulta_aluno_por_matricula(Aluno * al, int tamanho, int matricula);

#endif /* STRUCT_H_INCLUDED */
