#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main (){
 	Aluno aluno1 = {1, "Fulano", 9.0, 9.5, 10.0};
 	Aluno aluno2 = {2, "Ciclano", 9.0, 5.5, 10.0};
 	Aluno aluno3 = {3, "Beltrano", 6.0, 9.5, 10.0};

 	Lista * li = cria_lista();

 	printf("lista vazia? %i \n", lista_vazia(li));

 	insere_lista_inicio(li, aluno3);
 	insere_lista_inicio(li, aluno2);
 	insere_lista_inicio(li, aluno1);

 	printf("----------------------------- \n");

 	printf("tamanho da lista? %i \n", tamanho_lista(li));
 	imprime_lista(li);

 	printf("----------------------------- \n");

 	// remove_lista_inicio(li);
 	// remove_lista_inicio(li);

 	// printf("tamanho da lista? %i \n", tamanho_lista(li));
 	// imprime_lista(li);

 	// printf("lista vazia? %i \n", lista_vazia(li));
 	// printf("tamanho da lista? %i \n", tamanho_lista(li));

	libera_lista(li);

 	printf("----------------------------- \n");

 	printf("lista vazia? %i \n", lista_vazia(li));
 	printf("tamanho da lista? %i \n", tamanho_lista(li));


   return 0;
}
