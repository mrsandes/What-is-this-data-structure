#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

static int incr(int i) {
	return (i + 1) % N;
}

//Funcoes de fila com vetor

Fila_vetor *fila_vetor_cria() {
	Fila_vetor *f = (Fila_vetor*)malloc(sizeof(Fila_vetor));
	f->n = 0;
	f->ini = 0;

	return f;
}

void fila_vetor_insere(Fila_vetor *f, float v) {
	int fim;

	if (f->n == N) {
		printf("Capacidade da fila estourou\n");
		exit(1);
	}

	fim = (f->ini + f->n) % N;
	f->vet[fim] = v;
	f->n++;
}

float fila_vetor_retira(Fila_vetor *f) {
	float v;

	if (fila_vetor_vazia(f)) {
		printf("Fila vazia!\n");
		exit(1);
	}

	v = f->vet[f->ini];
	f->ini = (f->ini + 1) % N;
	f->n--;

	return v;
}

int fila_vetor_vazia(Fila_vetor *f) {
	return (f->n == 0);
}

void fila_vetor_libera(Fila_vetor *f) {
	free(f);
}

//lista encadeada

Fila_lista *fila_lista_cria() {
	Fila_lista *f = (Fila_lista*)malloc(sizeof(Fila_lista));
	f->ini = f->fim = NULL;

	return f;
}

void fila_lista_insere(Fila_lista *f, int v) {
	Listaa *n = (Listaa*)malloc(sizeof(Listaa));
	int i;

	n->info = v;

	n->prox = NULL;

	if (f->fim != NULL) {
        f->fim->prox = n;
    }

	else {
        f->ini = n;
    } 

	f->fim = n;
}

int fila_lista_retira(Fila_lista *f) {
	Listaa *t;
	int v;

	if (fila_lista_vazia(f)) {
		exit(1);
	}

	t = f->ini;
	v = t->info;
	f->ini = t->prox;

	if (f->ini == NULL) {
        f->fim = NULL;
    }

	free(t);
	return v;
}

int fila_lista_vazia(Fila_lista *f) {
	return (f->ini == NULL);
}

void fila_lista_libera(Fila_lista *f) {
	Listaa *q = f->ini;

	while (q != NULL) {
		Listaa *t = q->prox;
		free(q);
		q = t;
	}

	free(f);
}

Listaa *fila_lista_busca(Fila_lista *fila, int informacao) {
	Listaa *q;

	for (q = fila->ini; q != NULL; q = q->prox) {
		if (informacao == q->info) {
			return q;
		}
	}

	return NULL;
}

//funcoes de impressao

void fila_vetor_imprime(Fila_vetor *f) {
	int i;

	for (i = 0; i < f->n; i++) {
        printf("%f \n", f->vet[(f->ini + i) % N]);
    }
}

void fila_lista_imprime(Fila_lista *f) {
	Listaa *q;

	for (q = f->ini; q != NULL; q = q->prox) {
       printf("\t%d\n",q->info); 
    }
}