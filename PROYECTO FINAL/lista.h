#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    void *dato;
    struct Nodo *sig;
} Nodo;

typedef struct {
    Nodo *inicio;
} Lista;

void iniciarLista(Lista *l);

void insertarLista(Lista *l, void *dato);

#endif


