#ifndef FILA_H
#define FILA_H

#define N 100

//definindo fila com vetor

struct fila_vetor {
	int n;
	int ini;
	float vet[N];
};

typedef struct fila_vetor Fila_vetor;

//definindo fila com lista

struct listaa {
	int info;
	struct listaa *prox;
};

typedef struct listaa Listaa;

struct fila_lista {
	Listaa *ini;
	Listaa *fim;
};

typedef struct fila_lista Fila_lista;

//Funcoes de fila com vetor

Fila_vetor *fila_vetor_cria();

void fila_vetor_insere(Fila_vetor *f, float v);

float fila_vetor_retira(Fila_vetor *f);

int fila_vetor_vazia(Fila_vetor *f);

void fila_vetor_libera(Fila_vetor *f);

//fila com lista

Fila_lista *fila_lista_cria();

void fila_lista_insere(Fila_lista *f, int v);

int fila_lista_retira(Fila_lista *f);

int fila_lista_vazia(Fila_lista *f);

void fila_lista_libera(Fila_lista *f);

Listaa* fila_lista_busca(Fila_lista *fila, int informacao);

//funcoes de impressao

void fila_vetor_imprime(Fila_vetor *f);

void fila_lista_imprime(Fila_lista *f);

#endif