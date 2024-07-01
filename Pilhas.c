#include <stdio.h>
#include <stdlib.h>
#include "Pilhas.h"

//Funcoes de pilha com vetor

Pilha_vetor *pilha_vetor_cria() {
	Pilha_vetor *p = (Pilha_vetor*)malloc(sizeof(Pilha_vetor));
	p->n = 0;

	return p;
}

void pilha_vetor_push(Pilha_vetor *p, char v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

char pilha_vetor_pop(Pilha_vetor *p) {
	if (pilha_vetor_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}

	return p->vet[--p->n];
}

int pilha_vetor_vazia(Pilha_vetor *p) {
	return (p->n == 0);
}

void pilha_vetor_libera(Pilha_vetor *p) {
	free(p);
}

void pilha_vetor_imprime(Pilha_vetor *p) {
	int i;

	for (i = p->n - 1; i >= 0; i--) {
		printf("%c\n", p->vet[i]);
	}
}

//pilhas com lista

Pilha_lista *pilha_lista_cria() {
	Pilha_lista *p = (Pilha_lista *)malloc(sizeof(Pilha_lista));
	p->prim = NULL;
	
	return p;
}

void pilha_lista_push(Pilha_lista *p, int v) {
	Listab *l = (Listab*)malloc(sizeof(Listab));
	l->info = v;
	l->prox = p->prim;
	p->prim = l;
}

int pilha_lista_pop(Pilha_lista *p) {
	Listab *l;
	int c;

	if (pilha_lista_vazia(p)) {
		exit(1);
	}
    
	l = p->prim;
	c = l->info;
	p->prim = l->prox;

	free(l);
	return c;
}

int pilha_lista_vazia(Pilha_lista *p) {
	return (p->prim == NULL);
}

void pilha_lista_libera(Pilha_lista *p) {
	Listab *l = p->prim;

	while(l != NULL) {
		Listab *t = l->prox;
		free(l);
		l = t;
	}

	free(p);
}

void pilha_lista_imprime(Pilha_lista *p) {
	Listab *l;

	for (l = p->prim; l != NULL; l = l->prox) {
		printf("%d\n", l->info);
	}
}