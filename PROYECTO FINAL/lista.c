#include <stdlib.h>
// Biblioteca estándar que permite utilizar funciones de memoria dinámica como malloc.
#include "lista.h"
// Incluye el archivo de encabezado donde se encuentran las estructuras
// y prototipos de funciones de la lista enlazada.

// Función que inicializa una lista.
// Asigna NULL al inicio para indicar que la lista está vacía.
void iniciarLista(Lista *l) {
    l->inicio = NULL;
}

// Función que inserta un nuevo nodo al final de la lista.
// Recibe la lista y el dato que se desea almacenar.
void insertarLista(Lista *l, void *dato) {

    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    // Reserva memoria dinámica para crear un nuevo nodo.

    nuevo->dato = dato;
    nuevo->sig = NULL;
    // Guarda el dato en el nodo y establece que aún no apunta a otro nodo.

    if(l->inicio == NULL) {
        // Verifica si la lista está vacía.

        l->inicio = nuevo;
        // Si está vacía, el nuevo nodo se convierte en el inicio de la lista.

    } else {

        Nodo *aux = l->inicio;
        // Crea un nodo auxiliar para recorrer la lista desde el inicio.

        while(aux->sig != NULL) {
            aux = aux->sig;
        }
        // Recorre la lista hasta encontrar el último nodo.

        aux->sig = nuevo;
        // Conecta el último nodo de la lista con el nuevo nodo creado.
    }
}
