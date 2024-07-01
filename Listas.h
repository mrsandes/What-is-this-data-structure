#ifndef LISTAS_H
#define LISTAS_H

//definindo lista encadeada

struct lista {
	int info;
	struct lista *prox;
};

typedef struct lista Lista;

//definindo lista duplamente encadeada

struct listadupla {
	int info;
	struct listadupla *ant;
	struct listadupla *prox;
};

typedef struct listadupla Listadupla;

//Funcoes de lista encadeada

Lista* lista_cria();

Lista* lista_insere(Lista *l, int i);

void lista_imprime(Lista *l);

int lista_vazia(Lista *l);

Lista* lista_busca(Lista *l, int v);

Lista* lista_retira(Lista *l, int v);

void lista_libera(Lista *l);

Lista* lista_insere_ordenado(Lista *l, int v);

int lista_tamanho(Lista *l);

int lista_igual(Lista *l1, Lista *l2);

//listas circulares

void listacirc_imprime(Lista *l); 

Lista* listacirc_transforma(Lista *l);

void listacirc_libera(Lista *l);

Lista* listacirc_busca(Lista *l, int v);

int listacirc_tamanho(Lista *l);

//listas duplamente encadeadas

Listadupla* listadupla_insere(Listadupla *l, int v);

Listadupla* listadupla_busca(Listadupla *l, int v);

Listadupla* listadupla_retira(Listadupla *l, int v);

#endif