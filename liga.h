#include "equipos.h"
#ifndef LIGA_H
#define LIGA_H

//Función para crear una liga vacía
//Devuelve una liga con:
//Nombre=cadena vacía
//Numero de equipos =0
liga_t crearLiga();

//Función que modifica la lista de equipos de una liga añadiendo un equipo al final de la misma
//-Modifica el los equipos de la liga, añadiendo un equipo al final del array de equipos de la liga 
// y sumando 1 al número de equipos.
//-Después de añadirlo, inicializa las estadísticas de ese equipo a 0

//Las estadísticas de un equipo se encuentran en la lista de estadísticas de la estructura liga.
// -Para el equipo almacenado en la posición "n" de la lista de equipos de la liga,
// sus estadísticas se encontrarán en la posición "n" del array de estadísticas de la liga
// -No confundir con el identificador del equipo, este se corresponde con su posición dentro de la lista
// de equipos global.
void introducirEquipoEnLiga(liga_t* liga,equipo_t* equipo);


void borrarLiga(liga_t liga);

#endif
