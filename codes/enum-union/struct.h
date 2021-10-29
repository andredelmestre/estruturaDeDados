#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define MAX 10
// TADs
enum semana{
	SEG, TER, QUA, QUI, SEX, SAB, DOM
}typedef Semana;

enum partido{
	PDT=12, PT=13, MDB=15, PSL=17, PSDB=45
}typedef Partido;

union ideologia{
	int esquerda; 
    int direita;
    int centro; 
}typedef Ideologia;

struct macro{
	union{
		int fat;
		int gordura;
	};
	union{
		int protein;
		int proteina;
	};
	union{
		int carb;
		int carboidrato;
	};
}typedef Macro;

struct mistura{
	Semana dia;
	Partido sigla;
	Macro refeicao;
}typedef Louco;








void limpa();


#endif /* STRUCT_H_INCLUDED */
