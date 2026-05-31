#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "estructuras.h"

typedef struct {

    Lista regiones;
    Lista zonas;
    Lista regimientos;
    Lista batallones;
    Lista companias;
    Lista soldados;

} Sistema;

/* =========================================
        VALIDAR ID REPETIDO
========================================= */

int existeID(Lista *l, char id[]) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Region *r = (Region*) aux->dato;

        if(strcmp(r->id, id) == 0) {
            return 1;
        }

        aux = aux->sig;
    }

    return 0;
}

/* =========================================
            MOSTRAR LISTAS
========================================= */

void mostrarRegiones(Lista *l) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        Region *r = (Region*) aux->dato;

        printf("%d. %s\n", i, r->nombre);

        aux = aux->sig;
        i++;
    }
}

void mostrarZonas(Lista *l) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        Zona *z = (Zona*) aux->dato;

        printf("%d. %s\n", i, z->nombre);

        aux = aux->sig;
        i++;
    }
}

void mostrarRegimientos(Lista *l) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        Regimiento *r = (Regimiento*) aux->dato;

        printf("%d. %s\n", i, r->nombre);

        aux = aux->sig;
        i++;
    }
}

void mostrarBatallones(Lista *l) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        Batallon *b = (Batallon*) aux->dato;

        printf("%d. BATALLON %d\n", i, b->numero);

        aux = aux->sig;
        i++;
    }
}

void mostrarCompanias(Lista *l) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        Compania *c = (Compania*) aux->dato;

        printf("%d. %s\n", i, c->nombre);

        aux = aux->sig;
        i++;
    }
}

/* =========================================
            OBTENER ELEMENTOS
========================================= */

Region *obtenerRegion(Lista *l, int pos) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        if(i == pos)
            return (Region*) aux->dato;

        aux = aux->sig;
        i++;
    }

    return NULL;
}

Zona *obtenerZona(Lista *l, int pos) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        if(i == pos)
            return (Zona*) aux->dato;

        aux = aux->sig;
        i++;
    }

    return NULL;
}

Regimiento *obtenerRegimiento(Lista *l, int pos) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        if(i == pos)
            return (Regimiento*) aux->dato;

        aux = aux->sig;
        i++;
    }

    return NULL;
}

Batallon *obtenerBatallon(Lista *l, int pos) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        if(i == pos)
            return (Batallon*) aux->dato;

        aux = aux->sig;
        i++;
    }

    return NULL;
}

Compania *obtenerCompania(Lista *l, int pos) {

    Nodo *aux = l->inicio;
    int i = 1;

    while(aux != NULL) {

        if(i == pos)
            return (Compania*) aux->dato;

        aux = aux->sig;
        i++;
    }

    return NULL;
}

/* =========================================
            AGREGAR REGION
========================================= */

void agregarRegion(Sistema *s) {

    Region *r = (Region*) malloc(sizeof(Region));

    printf("\nID REGION: ");
    scanf("%10s", r->id);

    if(existeID(&s->regiones, r->id)) {

        printf("EL ID YA EXISTE\n");
        free(r);
        return;
    }

    printf("NOMBRE: ");
    scanf(" %40[^\n]", r->nombre);

    insertarLista(&s->regiones, r);

    printf("REGION AGREGADA\n");
}

/* =========================================
            AGREGAR ZONA
========================================= */

void agregarZona(Sistema *s) {

    int op;

    if(s->regiones.inicio == NULL) {

        printf("PRIMERO DEBE EXISTIR UNA REGION\n");
        return;
    }

    Zona *z = (Zona*) malloc(sizeof(Zona));

    printf("\nID ZONA: ");
    scanf("%10s", z->id);

    if(existeID(&s->zonas, z->id)) {

        printf("EL ID YA EXISTE\n");
        free(z);
        return;
    }

    printf("NOMBRE: ");
    scanf(" %40[^\n]", z->nombre);

    printf("\nREGIONES DISPONIBLES\n");
    mostrarRegiones(&s->regiones);

    printf("SELECCIONA REGION: ");
    scanf("%d", &op);

    Region *r = obtenerRegion(&s->regiones, op);

    if(r == NULL) {

        printf("OPCION INVALIDA\n");
        free(z);
        return;
    }

    strcpy(z->idRegion, r->id);

    insertarLista(&s->zonas, z);

    printf("ZONA AGREGADA\n");
}

/* =========================================
        AGREGAR REGIMIENTO
========================================= */

void agregarRegimiento(Sistema *s) {

    int opZona;
    int opTipo;

    if(s->zonas.inicio == NULL) {

        printf("PRIMERO DEBE EXISTIR UNA ZONA\n");
        return;
    }

    Regimiento *r = (Regimiento*) malloc(sizeof(Regimiento));

    printf("\nID REGIMIENTO: ");
    scanf("%10s", r->id);

    if(existeID(&s->regimientos, r->id)) {

        printf("EL ID YA EXISTE\n");
        free(r);
        return;
    }

    printf("NOMBRE: ");
    scanf(" %40[^\n]", r->nombre);

    printf("\nTIPOS\n");
    printf("1. INFANTERIA\n");
    printf("2. CABALLERIA\n");
    printf("3. ARTILLERIA\n");
    printf("4. LOGISTICO\n");
    printf("5. INGENIEROS\n");

    printf("OPCION: ");
    scanf("%d", &opTipo);

    switch(opTipo) {

        case 1:
            strcpy(r->tipo, "INFANTERIA");
            break;

        case 2:
            strcpy(r->tipo, "CABALLERIA");
            break;

        case 3:
            strcpy(r->tipo, "ARTILLERIA");
            break;

        case 4:
            strcpy(r->tipo, "LOGISTICO");
            break;

        case 5:
            strcpy(r->tipo, "INGENIEROS");
            break;

        default:
            printf("TIPO INVALIDO\n");
            free(r);
            return;
    }

    printf("\nZONAS DISPONIBLES\n");
    mostrarZonas(&s->zonas);

    printf("SELECCIONA ZONA: ");
    scanf("%d", &opZona);

    Zona *z = obtenerZona(&s->zonas, opZona);

    if(z == NULL) {

        printf("OPCION INVALIDA\n");
        free(r);
        return;
    }

    strcpy(r->idZona, z->id);

    insertarLista(&s->regimientos, r);

    printf("REGIMIENTO AGREGADO\n");
}

/* =========================================
            AGREGAR BATALLON
========================================= */

void agregarBatallon(Sistema *s) {

    int opRegimiento;
    int opTipo;

    if(s->regimientos.inicio == NULL) {

        printf("PRIMERO DEBE EXISTIR UN REGIMIENTO\n");
        return;
    }

    Batallon *b = (Batallon*) malloc(sizeof(Batallon));

    printf("\nID BATALLON: ");
    scanf("%10s", b->id);

    if(existeID(&s->batallones, b->id)) {

        printf("EL ID YA EXISTE\n");
        free(b);
        return;
    }

    printf("NUMERO: ");
    scanf("%d", &b->numero);

    printf("\nTIPOS\n");
    printf("1. INFANTERIA\n");
    printf("2. CABALLERIA\n");
    printf("3. ARTILLERIA\n");
    printf("4. LOGISTICO\n");
    printf("5. INGENIEROS\n");

    printf("OPCION: ");
    scanf("%d", &opTipo);

    switch(opTipo) {

        case 1:
            strcpy(b->tipo, "INFANTERIA");
            break;

        case 2:
            strcpy(b->tipo, "CABALLERIA");
            break;

        case 3:
            strcpy(b->tipo, "ARTILLERIA");
            break;

        case 4:
            strcpy(b->tipo, "LOGISTICO");
            break;

        case 5:
            strcpy(b->tipo, "INGENIEROS");
            break;

        default:
            printf("TIPO INVALIDO\n");
            free(b);
            return;
    }

    printf("\nREGIMIENTOS DISPONIBLES\n");
    mostrarRegimientos(&s->regimientos);

    printf("SELECCIONA REGIMIENTO: ");
    scanf("%d", &opRegimiento);

    Regimiento *r = obtenerRegimiento(&s->regimientos, opRegimiento);

    if(r == NULL) {

        printf("OPCION INVALIDA\n");
        free(b);
        return;
    }

    strcpy(b->idRegimiento, r->id);

    insertarLista(&s->batallones, b);

    printf("BATALLON AGREGADO\n");
}

/* =========================================
            AGREGAR COMPANIA
========================================= */

void agregarCompania(Sistema *s) {

    int opBatallon;

    if(s->batallones.inicio == NULL) {

        printf("PRIMERO DEBE EXISTIR UN BATALLON\n");
        return;
    }

    Compania *c = (Compania*) malloc(sizeof(Compania));

    printf("\nID COMPANIA: ");
    scanf("%10s", c->id);

    if(existeID(&s->companias, c->id)) {

        printf("EL ID YA EXISTE\n");
        free(c);
        return;
    }

    printf("NOMBRE: ");
    scanf(" %40[^\n]", c->nombre);

    printf("\nBATALLONES DISPONIBLES\n");
    mostrarBatallones(&s->batallones);

    printf("SELECCIONA BATALLON: ");
    scanf("%d", &opBatallon);

    Batallon *b = obtenerBatallon(&s->batallones, opBatallon);

    if(b == NULL) {

        printf("OPCION INVALIDA\n");
        free(c);
        return;
    }

    strcpy(c->idBatallon, b->id);

    insertarLista(&s->companias, c);

    printf("COMPANIA AGREGADA\n");
}

/* =========================================
            AGREGAR SOLDADO
========================================= */

void agregarSoldado(Sistema *s) {

    int opCompania;
    int opGrado;

    if(s->companias.inicio == NULL) {

        printf("PRIMERO DEBE EXISTIR UNA COMPANIA\n");
        return;
    }

    Soldado *so = (Soldado*) malloc(sizeof(Soldado));

    printf("\nID SOLDADO: ");
    scanf("%10s", so->id);

    if(existeID(&s->soldados, so->id)) {

        printf("EL ID YA EXISTE\n");
        free(so);
        return;
    }

    printf("NOMBRE: ");
    scanf(" %40[^\n]", so->nombre);

    printf("\nGRADOS\n");
    printf("1. GENERAL\n");
    printf("2. CORONEL\n");
    printf("3. MAYOR\n");
    printf("4. CAPITAN\n");
    printf("5. TENIENTE\n");
    printf("6. SARGENTO\n");
    printf("7. SOLDADO\n");

    printf("OPCION: ");
    scanf("%d", &opGrado);

    switch(opGrado) {

        case 1:
            strcpy(so->grado, "GENERAL");
            break;

        case 2:
            strcpy(so->grado, "CORONEL");
            break;

        case 3:
            strcpy(so->grado, "MAYOR");
            break;

        case 4:
            strcpy(so->grado, "CAPITAN");
            break;

        case 5:
            strcpy(so->grado, "TENIENTE");
            break;

        case 6:
            strcpy(so->grado, "SARGENTO");
            break;

        case 7:
            strcpy(so->grado, "SOLDADO");
            break;

        default:
            printf("GRADO INVALIDO\n");
            free(so);
            return;
    }

    printf("\nCOMPANIAS DISPONIBLES\n");
    mostrarCompanias(&s->companias);

    printf("SELECCIONA COMPANIA: ");
    scanf("%d", &opCompania);

    Compania *c = obtenerCompania(&s->companias, opCompania);

    if(c == NULL) {

        printf("OPCION INVALIDA\n");
        free(so);
        return;
    }

    strcpy(so->idCompania, c->id);

    insertarLista(&s->soldados, so);

    printf("SOLDADO AGREGADO\n");
}

/* =========================================
            VISUALIZAR DATOS
========================================= */

void verRegiones(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Region *r = (Region*) aux->dato;

        printf("\nID: %s", r->id);
        printf("\nNOMBRE: %s\n", r->nombre);

        aux = aux->sig;
    }
}

void verZonas(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Zona *z = (Zona*) aux->dato;

        printf("\nID: %s", z->id);
        printf("\nNOMBRE: %s", z->nombre);
        printf("\nID REGION: %s\n", z->idRegion);

        aux = aux->sig;
    }
}

void verRegimientos(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Regimiento *r = (Regimiento*) aux->dato;

        printf("\nID: %s", r->id);
        printf("\nNOMBRE: %s", r->nombre);
        printf("\nTIPO: %s\n", r->tipo);

        aux = aux->sig;
    }
}

void verBatallones(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Batallon *b = (Batallon*) aux->dato;

        printf("\nID: %s", b->id);
        printf("\nNUMERO: %d", b->numero);
        printf("\nTIPO: %s\n", b->tipo);

        aux = aux->sig;
    }
}

void verCompanias(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Compania *c = (Compania*) aux->dato;

        printf("\nID: %s", c->id);
        printf("\nNOMBRE: %s\n", c->nombre);

        aux = aux->sig;
    }
}

void verSoldados(Lista *l) {

    Nodo *aux = l->inicio;

    while(aux != NULL) {

        Soldado *s = (Soldado*) aux->dato;

        printf("\nID: %s", s->id);
        printf("\nNOMBRE: %s", s->nombre);
        printf("\nGRADO: %s\n", s->grado);

        aux = aux->sig;
    }
}

/* =========================================
                MENUS
========================================= */

void menuRegistro(Sistema *s) {

    int op;

    do {

        printf("\n===== REGISTRO =====\n");
        printf("1. REGION\n");
        printf("2. ZONA\n");
        printf("3. REGIMIENTO\n");
        printf("4. BATALLON\n");
        printf("5. COMPANIA\n");
        printf("6. SOLDADO\n");
        printf("7. REGRESAR\n");

        printf("OPCION: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                agregarRegion(s);
                break;

            case 2:
                agregarZona(s);
                break;

            case 3:
                agregarRegimiento(s);
                break;

            case 4:
                agregarBatallon(s);
                break;

            case 5:
                agregarCompania(s);
                break;

            case 6:
                agregarSoldado(s);
                break;
        }

    } while(op != 7);
}

void visualizarDatos(Sistema *s) {

    printf("\n===== REGIONES =====\n");
    verRegiones(&s->regiones);

    printf("\n===== ZONAS =====\n");
    verZonas(&s->zonas);

    printf("\n===== REGIMIENTOS =====\n");
    verRegimientos(&s->regimientos);

    printf("\n===== BATALLONES =====\n");
    verBatallones(&s->batallones);

    printf("\n===== COMPANIAS =====\n");
    verCompanias(&s->companias);

    printf("\n===== SOLDADOS =====\n");
    verSoldados(&s->soldados);
}

void menuPrincipal(Sistema *s) {

    int op;

    do {

        printf("\n===== SISTEMA MILITAR =====\n");
        printf("1. REGISTROS\n");
        printf("2. VISUALIZAR DATOS\n");
        printf("3. SALIR\n");

        printf("OPCION: ");
        scanf("%d", &op);

        switch(op) {

            case 1:
                menuRegistro(s);
                break;

            case 2:
                visualizarDatos(s);
                break;

            case 3:
                printf("SALIENDO...\n");
                break;

            default:
                printf("OPCION INVALIDA\n");
        }

    } while(op != 3);
}

/* =========================================
                    MAIN
========================================= */

int main() {

    Sistema sistema;

    iniciarLista(&sistema.regiones);
    iniciarLista(&sistema.zonas);
    iniciarLista(&sistema.regimientos);
    iniciarLista(&sistema.batallones);
    iniciarLista(&sistema.companias);
    iniciarLista(&sistema.soldados);

    menuPrincipal(&sistema);

    return 0;
}
