#include "tipos.h"
#ifndef JUGADORES_H
#define JUGADORES_H
//Pide por pantalla los datos de un jugador. Devuelve una estructura de tipo jugador_t con sus datos iniciados
jugador_t pideDatosJugador();
//Dado un puntero a un jugador que se pasa por parámetros, muestra por pantalla sus datos personales
void muestraJugador(jugador_t* jugador);

void borrarJugador(jugador_t jugador);

//Función que, dada una cadena que contiene el tipo de un jugador, devuelve el valor enumerado equivalente.
//Ej:
// char* tipoJugador="portero"
// Si tipoJugador es igual a "portero"
//	  devolver valor enumerado portero
tipoJugador_e buscaTiposJugador(const char* tipoJugador);



#endif
