#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"

//Funcoes de lista encadeada

Lista* lista_cria() {
	return NULL;
}

Lista* lista_insere(Lista *l, int i) {
	Lista *novo = (Lista*)malloc(sizeof(Lista));

	novo->info = i;
	novo->prox = l;

	return novo;
}

void lista_imprime(Lista *l) {
	Lista *p;

	for (p = l; p != NULL; p = p->prox) {
		printf("Valor: %d\n", p->info);
	}
}

int lista_vazia(Lista *l) {
	if (l == NULL)
		return 1;

	else
		return 0;
}

Lista* lista_busca(Lista *l, int v) {
	Lista *p;

	for (p = l; p != NULL; p = p->prox) {
		if (p->info == v) {
			return p;
		}
	}

	if (p == NULL) {
		return NULL;
	}
}

Lista* lista_retira(Lista *l, int v) {
	Lista *p = l;
	Lista *ant = NULL;

	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}

	if (p == NULL) {
		printf("Elemento não encontrado\n");
		return l;
	}

	if (ant == NULL) {
		l = p->prox;
	}

	else {
		ant->prox = p->prox;
	}

	free(p);
	return l;
}

void lista_libera(Lista *l) {
	Lista *p = l;

	while (p != NULL) {
		Lista *t = p->prox;
		free(p);
		p = t;
	}
}

Lista* lista_insere_ordenado(Lista *l, int v) {
	Lista *novo;

	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;

	Lista *ant = NULL;
	Lista *p = l;

	while (p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}

	if (ant == NULL) {
		novo->prox = l;

		return novo;
	}

	else {
		ant->prox = novo;
		novo->prox = p;

		return l;
	}
}

int lista_tamanho(Lista *l) {
	Lista *p;
	int tam = 0;

	for (p = l; p != NULL; p = p->prox) {
		tam++;		
	}
	
	return tam;	
}

int lista_igual(Lista *l1, Lista *l2) {
	Lista *p1;
	Lista *p2;
	int tam1 = 0, tam2 = 0;

	//calculando o tamanho
	tam1 = lista_tamanho(l1);
	tam2 = lista_tamanho(l2);

	p1 = l1;
	p2 = l2;

	if (tam1 != tam2) {
		return 2; //tamanho diferente
	}

	else {
		while (p1 != NULL) {
			if (p1->info == p2->info) {
				p1 = p1->prox;
				p2 = p2->prox;
			}

			else return 0; //diferente
		}
	}

	return 1; //igual
}

//listas circulares

void listacirc_imprime(Lista *l) {
	Lista *p = l;

	if (p) {
		do {
			printf("%d ", p->info);
			p = p->prox;
		} while (p != l);
	}

	printf("\n");
}

Lista* listacirc_transforma(Lista *l) {
	Lista *p = l;

	while (p->prox != NULL) {
		p = p->prox;
	}

	if (l == NULL) {
		return l;
	}

	else {
		p->prox = l;

		return l;
	}
}

void listacirc_libera(Lista *l) {
	Lista *p = l;

	do {
		Lista *t = p->prox;
		free(p);
		p = t;
	} while (p != l);
}

Lista* listacirc_busca(Lista *l, int v) {
	Lista *p = l;

	do {
		if (p->info == v) {
			return p;
		}

		else {
			p = p->prox;
		}
	} while (p != l);

	if (p == l) {
		printf("Elemento não encontrado\n");
		
		return NULL;
	}
}

int listacirc_tamanho(Lista *l) {
	Lista *p = l;
	int tam = 0;

	if (p) {
		do {
			tam++;
			p = p->prox;
		} while (p != l);
	}
	
	return tam;	
}

//listas duplamente encadeadas

Listadupla* listadupla_insere(Listadupla *l, int v) {
	Listadupla *novo = (Listadupla*)malloc(sizeof(Listadupla));
	novo->prox = l;
	novo->ant = NULL;
	novo->info = v;

	if (l != NULL) {
		l->ant = novo;
	}

	return novo;
}

Listadupla* listadupla_busca(Listadupla *l, int v) {
	Listadupla *p;

	for (p = l; p != NULL; p = p->prox) {
		if (p->info == v) {
			return p;
		}
	}

	return NULL;
}

Listadupla* listadupla_retira(Listadupla *l, int v) {
	Listadupla *p;
	p = listadupla_busca(l, v);

	if (p->ant == NULL) {
		l = p->prox;
	}

	else if (p->prox == NULL) {
		p->ant->prox = NULL;
	}

	else if (p == NULL) {
		printf("Célula não encontrada\n");
	}

	else {
		p->ant->prox = p->prox;
	}
	
	return l;
}