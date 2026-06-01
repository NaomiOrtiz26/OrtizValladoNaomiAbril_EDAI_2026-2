#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
// Evita que este archivo se incluya más de una vez durante la compilación

// Estructura que representa una región.
// Contiene un identificador y el nombre de la región.
typedef struct {
    char id[11];
    char nombre[41];
} Region;

// Estructura que representa una zona.
// Guarda su identificador, nombre y el id de la región a la que pertenece.
typedef struct {
    char id[11];
    char nombre[41];
    char idRegion[11];
} Zona;

// Estructura que representa un regimiento.
// Almacena un identificador, nombre, tipo de regimiento
// y el id de la zona correspondiente.
typedef struct {
    char id[11];
    char nombre[41];
    char tipo[20];
    char idZona[11];
} Regimiento;

// Estructura que representa un batallón.
// Contiene un identificador, número del batallón,
// tipo y el id del regimiento al que pertenece.
typedef struct {
    char id[11];
    int numero;
    char tipo[20];
    char idRegimiento[11];
} Batallon;

// Estructura que representa una compañía.
// Guarda un identificador, nombre y el id del batallón asociado.
typedef struct {
    char id[11];
    char nombre[41];
    char idBatallon[11];
} Compania;

// Estructura que representa un soldado.
// Contiene un identificador, nombre, grado militar
// y el id de la compañía a la que pertenece.
typedef struct {
    char id[11];
    char nombre[41];
    char grado[20];
    char idCompania[11];
} Soldado;

#endif
// Fin de la directiva de inclusión única
