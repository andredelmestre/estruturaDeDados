#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Aluno aluno;
 	Aluno* teste;

	printf("Listas Estaticas\n\n");

	printf("Criando lista...\n\n");
	li = cria_lista();

	printf("Liberando lista...\n\n");
	libera_lista(li);

	printf("Tamanho da lista = %d \n\n", tamanho_lista(li));

	printf("Lista cheia? %d \n\n", lista_cheia(li));

	printf("Lista vazia? %d \n\n", lista_vazia(li));

	aluno.matricula = 123;
	strcpy(aluno.nome, "Andre"); //aluno.nome = "Andre";
	aluno.n1 = 9.5;
	aluno.n2 = 9.0;
	aluno.rec = 10.0;

	printf("Inseriu na lista? %d \n\n", insere_lista_final(li, aluno));
    imprime_lista(li);

	aluno.matricula = 321;
	strcpy(aluno.nome, "Del Mestre"); //aluno.nome = "Andre";
	aluno.n1 = 0.5;
	aluno.n2 = 2.0;
	aluno.rec = 6.0;

	printf("Inseriu na lista? %d \n\n", insere_lista_final(li, aluno));
    imprime_lista(li);

	aluno.matricula = 666;
	strcpy(aluno.nome, "Jack"); //aluno.nome = "Andre";
	aluno.n1 = 0.5;
	aluno.n2 = 2.0;
	aluno.rec = 6.0;

	printf("Inseriu na lista? %d \n\n", insere_lista_final(li, aluno));
    imprime_lista(li);

	printf("Removeu da lista? %d \n\n", remove_lista_final(li));
    imprime_lista(li);


	aluno.matricula = 321;
	strcpy(aluno.nome, "Del Mestre"); //aluno.nome = "Andre";
	aluno.n1 = 7.5;
	aluno.n2 = 8.0;
	aluno.rec = 9.0;



    return 0;
}
