#include <stdlib.h>
#include "lista.h"

void iniciarLista(Lista *l) {

    l->inicio = NULL;
}

void insertarLista(Lista *l, void *dato) {

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));

    nuevo->dato = dato;
    nuevo->sig = NULL;

    if(l->inicio == NULL) {

        l->inicio = nuevo;

    } else {

        Nodo *aux = l->inicio;

        while(aux->sig != NULL) {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

