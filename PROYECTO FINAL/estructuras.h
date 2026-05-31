#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    char id[11];
    char nombre[41];
} Region;

typedef struct {
    char id[11];
    char nombre[41];
    char idRegion[11];
} Zona;

typedef struct {
    char id[11];
    char nombre[41];
    char tipo[20];
    char idZona[11];
} Regimiento;

typedef struct {
    char id[11];
    int numero;
    char tipo[20];
    char idRegimiento[11];
} Batallon;

typedef struct {
    char id[11];
    char nombre[41];
    char idBatallon[11];
} Compania;

typedef struct {
    char id[11];
    char nombre[41];
    char grado[20];
    char idCompania[11];
} Soldado;

#endif
