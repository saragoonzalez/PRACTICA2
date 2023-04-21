#include <stdlib.h>
#include <stdio.h>
#ifndef TIPOS_H
#define TIPOS_H




//Crear un enumerado llamado "tipoJugador_e"
// Podrá tener los siguientes tipos de jugador (no cambiar el orden):
//	portero,defensa, medio, delantero

//enumerado tipoJugador_e;
typedef enum tipoJugador_e{portero,defensa, medio, delantero} tipoJugador_e;

//Crear un enumerado llamado "tipoLista_e"
// El programa podrá crear listas de Jugadores, Equipos o Ligas
// Se usará este enumerado para indicar el tipo de lista que se va a usar
// El enumerado tendrá los valores jugadores, equipos y ligas

//enumerado tipoLista_e;
typedef enum tipoLista_e{jugadores, equipos, ligas} tipoLista_e;

//Estructura estadisticasJugador_t
//Crear una estructura que almacene los siguientes para un jugador:
//	número de partidos jugados
//  número de minutos jugados
//  número de goles totales marcados
//  número de asistencias
//  número de tarjetas amarillas
//  número de tarjetas rojas
//	número de balones perdidos
//  número de pases buenos
//  número de pases intentados
//	valoracion global

//estructura estadisticasJugador_t;
typedef struct estadisticasJugador_t{
    int partidos_jugados;
    int minutos_jugados;
    int goles_marcados;
    int asistencias;
    int tarjetas_amarillas;
    int tarjetas_rojas;
    int balones_perdidos;
    int pases_buenos;
    int pases_intentados;
    int valoracion;

}estadisticasJugador_t;


//Estructura estadisticasEquipo_t
//Crear una estructura que almacene los siguientes datos para un equipo:
//	Número de partidos jugados
//	Número de victorias
//	Número de empates
//	Número de derrotas
//	Número de goles a favor
//	Número de goles en contra
//	Diferencia de goles
//	Número de puntos en liga
	
//estructura estadisticasEquipo_t;
typedef struct estadisticasEquipo_t{
    int partidos_jugados;
    int victorias;
    int empates;
    int derrotas;
    int goles_favor;
    int goles_contra;
    int diferencia_goles;
    int puntos;
}estadisticasEquipo_t;

//Estructura jugador_t
//Crear una estructura que almacene los siguientes datos de un jugador:
//  Identificador del jugador (número único no repetible dentro del programa, se inicializará al añadir jugadores a listas)
//	Nombre y Apellidos del jugador
//	Puntero a un equipo al que pertenece (OBLIGATORIAMENTE, un puntero a una estructura de tipo "struct equipo_t*" )
//	Tipo del jugador (usar enumerado tipoJugador_e)
//  DNI del jugador (array de caracteres)
//  teléfono del jugador (array de caracteres)
//  Estadísticas jugador (usar la estructura estadisticasJugador_t)
struct equipo_t;
//estructura jugador_t;
typedef struct {
    int identificador;
    char *nombre;
    char *apellidos;
    char *dni;
    char *telefono;
    equipo_t* equipo;
    tipoJugador_e tipo;
    estadisticasJugador_t estadisticasJugador;
} jugador_t;


jugador_t *crear_jugador(char *nombre, char *dni, char *telefono) {
    jugador_t *jugador = malloc(sizeof(jugador_t));
    jugador->nombre = malloc(strlen(nombre) + 1);  // Asignamos memoria para el nombre del jugador
    jugador->dni = malloc(strlen(dni) + 1);  // Asignamos memoria para el DNI del jugador
    jugador->telefono = malloc(strlen(telefono) + 1);  // Asignamos memoria para el teléfono del jugador
    strcpy(jugador->nombre, nombre);
    strcpy(jugador->dni, dni);
    strcpy(jugador->telefono, telefono);
    return jugador;
}

void eliminar_jugador(jugador_t *jugador) {
    free(jugador->nombre);  // Liberamos la memoria asignada para el nombre del jugador
    free(jugador->dni);  // Liberamos la memoria asignada para el DNI del jugador
    free(jugador->telefono);  // Liberamos la memoria asignada para el teléfono del jugador
    free(jugador);
}


//Estructura equipo_t
//Crear una estructura que almacene los siguientes datos de un equipo:
//  Identificador del equipo (número único no repetible dentro del programa, se inicializará al añadir equipos a listas)
//	Array de punteros a jugadores (OBLIGATORIAMENTE, un array de punteros a estructuras de tipo "struct jugador_t*" )
//	Nombre del equipo
//	Número de jugadores en el equipo (empezará en 0, y se sumará 1 cada vez que se añada un ugador al equipo)

//estructura equipo_t;
typedef struct {
    int identificador;
    char *nombre;
    jugador_t **jugadores;
    int num_jugadores;
    int partidos_ganados;
    int partidos_empatados;
    int partidos_perdidos;
} equipo_t;

equipo_t *crear_equipo(char *nombre) {
    equipo_t *equipo = malloc(sizeof(equipo_t));
    equipo->nombre = malloc(strlen(nombre) + 1);  // Asignamos memoria para el nombre del equipo
    strcpy(equipo->nombre, nombre);
    equipo->jugadores = NULL;
    equipo->num_jugadores = 0;
    equipo->partidos_ganados = 0;
    equipo->partidos_empatados = 0;
    equipo->partidos_perdidos = 0;
    return equipo;
}

void eliminar_equipo(equipo_t *equipo) {
    free(equipo->nombre);  // Liberamos la memoria asignada para el nombre del equipo
    for (int i = 0; i < equipo->num_jugadores; i++) {
        eliminar_jugador(equipo->jugadores[i]);  // Eliminamos cada jugador
    }
    free(equipo->jugadores);  // Liberamos la memoria asignada para la lista de jugadores
    free(equipo);
}

// Estructura calendario_t
typedef struct {

    int*** emparejamientos;
    int numSemanas;
    int numJornadasPorSemana;

}calendario_t;

//Estructura liga_t
//Crear una estructura que almacene los siguientes datos de una liga:
//	Nombre de la liga
//	Array de punteros a equipos (OBLIGATORIAMENTE, un array de punteros a estructuras de tipo "struct equipo_t*" )
//  Array de estadísticas (usar la estructura estadisticasEquipo_t)
//  Número de equipos en la liga

//estructura liga_t;
typedef struct {
    int num_equipos;
    char *nombre;
    equipo_t **equipos;
    estadisticasEquipo_t *estadisticas;
    calendario_t calendario;
} liga_t;

liga_t *crear_liga(char *nombre) {
    liga_t *liga = malloc(sizeof(liga_t));
    liga->nombre = malloc(strlen(nombre) + 1);  // Asignamos memoria para el nombre de la liga
    strcpy(liga->nombre, nombre);
    liga->equipos = malloc(sizeof(equipo_t*) * liga.num_equipos);  // Asignamos memoria para la lista de equipos
    liga->estadisticas = malloc(sizeof(estadisticasEquipo_t) NUM_EQUIPOS_LIGA);  // Asignamos memoria para las estadísticas de cada equipo
    for (int i = 0; i < NUM_EQUIPOS_LIGA; i++) {
        liga->equipos[i] = NULL;  // Inicializamos cada puntero a equipo como NULL
    }
    return liga;
}

void eliminar_liga(liga_t *liga) {
    free(liga->nombre);  // Liberamos la memoria asignada para el nombre de la liga
    for (int i = 0; i < NUM_EQUIPOS_LIGA; i++) {
        if (liga->equipos[i] != NULL) {
            eliminar_equipo(liga->equipos[i]);  // Liberamos la memoria asignada para cada equipo
        }
    }
    free(liga->equipos);  // Liberamos la memoria asignada para la lista de equipos
    free(liga->estadisticas);  // Liberamos la memoria asignada para las estadísticas de cada equipo
    free(liga);
}


// TODO usar union
//Estructura lista_t
//Crear una estructura que permita almacenar listas de jugadores o equipos
//Se valorará que use el mínimo espacio (si se crea una lista de jugadores, no debería reservar espacio para equipos, y viceversa)
//Si la lista es de tipo "jugadores", sólo se usará el array de jugadores
//Si la lista es de tipo "equipos", sólo se usará el array de equipos
//La estructura contendrá los siguientes campos
//   Array de jugadores, de tamaño máximo "TAM_LISTA" (usar la estructura jugador_t)
//   Array de equipos, de tamaño máximo "TAM_LISTA" (usar la estructura equipo_t)
//   Tipo de lista creada (usar el enumerado tipoLista_e)
//   Número de huecos usados. Indica el tamaño usado de los arrays
//   Tamaño máximo de la lista. No se pueden introducir más elementos en los arrays si el número de huecos es igual al tamaño máximo

//estructura lista_t;

typedef struct lista{
    union {
		jugador_t* jugadores;
		equipo_t* equipos;
		liga_t* ligas;
	};
    
    int num;
    tipoLista_e tipoLista;
    int maximo;
}lista_t;
#endif

lista_t miLista;
miLista.numJugadores = 10;

// asignar memoria dinámica para el array de jugadores
miLista.numjugadores = malloc(miLista.numeroJugadores * sizeof(jugador_t));

