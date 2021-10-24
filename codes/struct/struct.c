#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void imprime_aluno(Aluno* al){
    if(al == NULL){
        printf("ERRO - aluno nao encontrado\n");
    }else{
        printf("Matricula: %d\n", al->matricula);
        printf("Nome: %s\n", al->nome);
        printf("Status: %c\n", al->status);
        printf("Notas: %f %f\n", al->n1, al->n2);
        printf("Recuperacao: %f\n", al->rec);
        printf("-------------------------------\n");
    }
}

void le_aluno(Aluno* al, int matricula){
    float media;
    // dentro do scanf estarei utilizando ponto para acessar os dados da struct
    printf("\n\nDigite as notas do aluno %i abaixo\n", matricula);
    printf("Nome do aluno\n");
    gets(al->nome);
    printf("Nota do 1 semestre\n");
    scanf("%f", &al->n1);
    printf("Nota do 1 semestre\n");
    scanf("%f", &al->n2);
    printf("Nota da reavaliacao\n");
    scanf("%f", &al->rec);

    al->matricula = matricula;
    // fora do scanf estarei utilizando seta para acessar os dados da struct
    if((al->n1 >= 6 && al->n2 >= 6) || al->rec >= 6){
        al->status = 'A';
    }else{
        al->status = 'R';
    }
}

void inicializa_aluno(Aluno* al, int matricula){
    al->matricula = matricula;
    strcpy(al->nome, "Fulano da Silva");
    al->status = 'R';
    al->n1 = 0.0;
    al->n2 = 0.0;
    al->rec = 0.0;
}

void limpa(){
    getchar();
    system("cls|clear");
}

float maior(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

float media_aluno(Aluno * al){
    if(al==NULL){
        printf("ERRO\n");
    }else{
        float media = (al->n1 + al->n2)/2;
        return maior(media, al->rec);
    }
}

float media_turma(Aluno * turma, int tamanho){
    int i;
    float soma=0;
    if(tamanho<=0 || turma==NULL){
        printf("ERRO\n");
        return 0.0;
    }else{
        for(i=0; i<tamanho; i++){
            soma += media_aluno(turma+i);
        }
        return soma/tamanho;
    }
}

int conta_status(Aluno * turma, int tamanho, char status){
    int i=0, cont=0;
    Aluno * aluno_aux;
    if(tamanho<=0 || turma==NULL){
        printf("ERRO\n");
        return 0;
    }else{
        for(i=0; i<tamanho; i++){
            aluno_aux = turma+i;
            if(aluno_aux->status == status){
                cont++;
            }
        }
        return cont;
    }
}

Aluno * consulta_aluno_por_matricula(Aluno * turma, int tamanho, int matricula){
    int i=0, cont=0;
    Aluno * aluno_aux;
    if(tamanho<=0 && turma==NULL){
        printf("ERRO\n");
        return NULL;
    }else{
        for(i=0; i<tamanho; i++){
            aluno_aux = turma+i;
            if(aluno_aux->matricula == matricula){
                return aluno_aux;
            }
        }
        return NULL;
    }
}
