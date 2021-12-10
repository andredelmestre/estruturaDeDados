//Arquivo FilaDin.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,rec;
}typedef Aluno;

//Definição do tipo Fila
struct elemento{
    Aluno dados;
    struct elemento *prox;
}typedef Elem;


//Definição do Nó Descritor da Fila
struct fila{
    Elem *inicio;
    Elem *final;
    int qtd;
}typedef Fila;


Fila* cria_Fila();
void libera_Fila(Fila* fi);
Aluno consulta_Fila(Fila* fi);
int insere_Fila(Fila* fi, Aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_aluno(Aluno al);
void imprime_Fila(Fila* fi);

