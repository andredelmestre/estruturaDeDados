#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
	Lista * li=NULL;
	Aluno al;
	int flag;

	printf("Criar Lista...\n");
	li = cria_lista();

	printf("li=%X \n tamanho_lista = %i\n", li, tamanho_lista(li));
	printf("lista_cheia(li)=%i \n lista_vazia(li) = %i\n", lista_cheia(li), lista_vazia(li));

	printf("------------------------------\n");
	
	al.matricula = 123;
	strcpy(al.nome, "Andre del Mestre");
	al.n1=9.1;
	al.n2=9.3;
	al.rec=9.8;

	flag = insere_lista_final(li, al);
	printf("inserir aluno na Lista... flag=%i\n", flag);

	al.matricula = 321;
	strcpy(al.nome, "Fulano da silva");
	al.n1=3.1;
	al.n2=4.3;
	al.rec=7.8;

	flag = insere_lista_final(li, al);
	printf("inserir aluno na Lista... flag=%i\n", flag);

	imprime_lista(li);


	flag = remove_lista_final(li);
	printf("deletar aluno na Lista... flag=%i\n", flag);

	imprime_lista(li);

	printf("------------------------------\n");

	printf("Liberar a Lista...\n");
	li = libera_lista(li);

	imprime_lista(li);
    return 0;
}
