#include "tipos.h"
#ifndef _CALENDARIO_
#define _CALENDARIO_

//Función que, dada una liga que ya tiene equipos asignados
//creará un calendario siguiendo las instrucciones del algoritmo
//de Fixture suministrado
void crearCalendarioParaLiga(liga_t* liga);
//dada una liga, muestra su calendario creado anteriormente
void mostrarCalendario(liga_t liga);
//libera los datos de calendario de una liga
void borrarCalendario(liga_t* liga);



#endif