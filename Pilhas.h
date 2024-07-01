#ifndef PILHAS_H
#define PILHAS_H

//definindo pilha com vetor

struct pilha_vetor {
	int n;
	char vet[N];
};

typedef struct pilha_vetor Pilha_vetor;

//definindo pilha com lista

struct listab {
	char info;
	struct listab *prox;
};

typedef struct listab Listab;

struct pilha_lista {
	Listab *prim;
};

typedef struct pilha_lista Pilha_lista;

//Funcoes de pilha com vetor

Pilha_vetor *pilha_vetor_cria();

void pilha_vetor_push(Pilha_vetor *p, char v);

char pilha_vetor_pop(Pilha_vetor *p);

int pilha_vetor_vazia(Pilha_vetor *p);

void pilha_vetor_libera(Pilha_vetor *p);

void pilha_vetor_imprime(Pilha_vetor *p);

//pilha com lista

Pilha_lista *pilha_lista_cria();

void pilha_lista_push(Pilha_lista *p, int v);

int pilha_lista_pop(Pilha_lista *p);

int pilha_lista_vazia(Pilha_lista *p);

void pilha_lista_libera(Pilha_lista *p);

void pilha_lista_imprime(Pilha_lista *p);

#endif