#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "Listas.h"
#include "Listas.c"
#include "Fila.h"
#include "Fila.c"
#include "Pilhas.h"
#include "Pilhas.c"

#define SUCESSO 0

int listap(Lista *filap, int num) {
    Lista *l;

    l = lista_busca(filap, num);

    if (l == NULL) {
        return 0;
    }

    if (l->prox == NULL) {
        filap = lista_retira(filap, num);
        return 1;
    }

    return 0;
}

void verifica(FILE *file, Fila_lista *fila, Pilha_lista *pilha, Lista *filap) {
    int cont, op, num;
    int Cfila = 0, Cpilha = 0, Cfilap = 0, retira = 0, test = 0, error = 0;

    fscanf(file, "%d", &cont);

    for (int i = 0; i < cont; i++) {
        fscanf(file, "%d %d", &op, &num);

        if (i == 0 && op == 2) {
            error++;
        }

        if (op == 1) {
            fila_lista_insere(fila, num);
            pilha_lista_push(pilha, num);
            filap = lista_insere_ordenado(filap, num);
        }

        if (op == 2 && error == 0) {
            retira++;

            if (fila_lista_retira(fila) == num && Cfila == retira - 1) {
                Cfila++;
            }
            
            if (pilha_lista_pop(pilha) == num && Cpilha == retira - 1) {
                Cpilha++;
            }

            if (listap(filap, num) == 1 && Cfilap == retira - 1) {
                Cfilap++;
            }
        }
    }

    if (Cfila == retira) {
        test++;
    }

    if (Cpilha == retira) {
        test++;
    }

    if (Cfilap == retira) {
        test++;
    }

    if (test == 0 || error == 1) {
        printf("impossible\n");
    }

    else if (test > 1) {
        printf("not sure\n");
    }

    else {
        if (Cfila == retira) {
            printf("queue\n");
        }

        if (Cpilha == retira) {
            printf("stack\n");
        }

        if (Cfilap == retira) {
            printf("priority queue\n");
        }
    }
}

int main(int argc, char const *argv[]) { 
    FILE *file;

    Fila_lista *fila;
    Pilha_lista *pilha;
    Lista *filap;

    file = fopen("Entrada.txt", "r");

    while (feof(file) == 0) {
        fila = fila_lista_cria();
        pilha = pilha_lista_cria();
        filap = lista_cria();

        verifica(file, fila, pilha, filap);

        fila_lista_libera(fila);
        pilha_lista_libera(pilha);
        lista_libera(filap);
    }

    fclose(file);	
    return SUCESSO;
}