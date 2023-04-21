#include "jugadores.h"
#ifndef EQUIPOS_H
#define EQUIPOS_H

//Pide por pantalla los datos de un Equipo. Devuelve una estructura de tipo equipo_t con sus datos iniciados
equipo_t pideDatosEquipo();
//Dado un puntero a un equipo que se pasa por parámetros, muestra por pantalla sus datos
void muestraEquipo(equipo_t* equipo);

//Dado un puntero a un jugador y un puntero a un equipo,
// introduce el jugador al final del array de jugadores del equipo 
// y suma 1 al número de jugadores del equipo
// También inicializa el equipo almacenado en la estructura del jugador
void introduceJugadorEnEquipo(jugador_t* jugador,equipo_t* equipo);

void borrarEquipo(equipo_t equipo);

#endif