#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Aluno aluno;			//parte 1
 	Aluno * aluno_ptr=NULL;	//parte 2
 	Aluno turma[10];		//parte 3

 	/******************************/
 	/* parte 1 - struct & typedef */
 	/******************************/

	aluno.matricula = 123;
    strcpy(aluno.nome, "Fulano da Silva");
	aluno.status = 'A';
	aluno.n1 = 9.5;
	aluno.n2 = 9.0;
	aluno.rec = 10.0;

    printf("-------------------------------\n");
    printf("Parte 1 -----------------------\n");
    printf("-------------------------------\n");
    printf("Matricula: %i\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Status: %c\n", aluno.status);
    printf("Notas: %f %f\n", aluno.n1, aluno.n2);
    printf("Recuperacao: %f\n", aluno.rec);
    printf("-------------------------------\n");

    limpa();

 // 	/******************************/
 // 	// parte 2 - struct e funcoes 
 // 	/******************************/

    printf("-------------------------------\n");
    printf("Parte 2 -----------------------\n");
    printf("-------------------------------\n");
    aluno_ptr = &aluno;
    printf("Imprime Aluno 1 ---------------\n");
	imprime_aluno(aluno_ptr);

    le_aluno(aluno_ptr, 123);
    printf("Imprime Aluno 2 ---------------\n");
	imprime_aluno(aluno_ptr);

    getchar();

    limpa();

    printf("Media de Aluno ----------------\n");
	float media = media_aluno(aluno_ptr);
    printf("\nMedia do aluno = %f\n", media);

 	/*****************************/
 	/* parte 3 - vetor de struct */
 	/*****************************/
    limpa();

	int i;
    printf("-------------------------------\n");
    printf("Parte 3 -----------------------\n");
    printf("-------------------------------\n");
    printf("Le Turma ----------------------\n");
    aluno_ptr = turma;
    for(i=0; i<8; i++){
        inicializa_aluno(aluno_ptr+i, i);
    }
    for(i=8; i<10; i++){
        le_aluno(aluno_ptr+i, i);
    }
    printf("Imprime Turma -----------------\n");
    for(i=0; i<10; i++){
		imprime_aluno(aluno_ptr+i);
    }

 	/******************************/
 	/* parte 4 - funcoes e struct */
 	/******************************/
    limpa();

    printf("-------------------------------\n");
    printf("Parte 4 -----------------------\n");
    printf("-------------------------------\n");
    printf("Media da Turma ----------------\n");
	float media_t = media_turma(turma, 10);
    printf("Media da turma = %f\n\n", media_t);

    printf("Conta Aprovados ---------------\n");
	int aprovados = conta_status(turma, 10, 'A');
    printf("N de aprovados da turma = %i\n\n", aprovados);

    printf("Conta Reprovados ---------------\n");
	int reprovados = conta_status(turma, 10, 'R');
    printf("N de reprovados da turma = %i\n\n", reprovados);

	Aluno * aluno_ptr_2=NULL;
    printf("Consulta Aluno ----------------\n");
	aluno_ptr_2 = consulta_aluno_por_matricula(turma, 10, 9);
	imprime_aluno(aluno_ptr_2);

    limpa();

    return 0;
}