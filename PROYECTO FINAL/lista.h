#ifndef LISTA_H
#define LISTA_H
// Evita que este archivo se incluya más de una vez durante la compilación

typedef struct Nodo {
    void *dato;
    // Apuntador genérico que puede almacenar cualquier tipo de dato

    struct Nodo *sig;
    // Apuntador al siguiente nodo de la lista enlazada
} Nodo;
// Definición de la estructura Nodo

typedef struct {
    Nodo *inicio;
    // Apuntador al primer nodo de la lista
} Lista;
// Definición de la estructura Lista

void iniciarLista(Lista *l);
// Declaración de la función que inicializa una lista vacía

void insertarLista(Lista *l, void *dato);
// Declaración de la función que inserta un dato en la lista

#endif // Fin de la directiva de inclusión única


