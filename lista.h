#include "tipos.h"
#ifndef _LISTA_T_
#define _LISTA_T_

//Funci�n para crear una lista gen�rica de un tipo concreto
//Recibe el tama�o m�ximo de la lista, debe ser menor o igual a "TAM_LISTA"
//Devuelve una lista con:
//tama�o m�ximo=tamLista
//tipo Lista=tipo
//Numero usados =0
lista_t crearLista(int tamLista, tipoLista_e tipo);

//Introduce un nuevo equipo al final de la lista.
//Consulta el numero de huecos usados. Si es menor al tama�o de la lista, 
//introducir� el equipo al final e incrementar� el n�mero de huecos usados
//Asigna el identificador del equipo a su posici�n dentro de la lista 
void introducirEquipoEnLista(lista_t* lista, equipo_t equipo);

//Introduce un nuevo jugador al final de la lista.
//Consulta el numero de huecos usados. Si es menor al tama�o de la lista, 
//Asigna el identificador del jugador a su posici�n dentro de la lista 
void introducirJugadorEnLista(lista_t* lista, jugador_t jugador);


//Dado el nombre de un jugador, devuelve el identificador del jugador (su posici�n dentro de la lista) almacenado
//en la lista
//Si no lo encuentra, devuelve -1 (valor no v�lido)
int buscaJugador(lista_t* listaJugadores, char* nombre);

//Dado el nombre de un equipo, devuelve el identificador del equipo (su posici�n dentro de la lista) almacenado
//en la lista
//Si no lo encuentra, devuelve -1 (valor no v�lido)
int  buscaEquipo(lista_t* listaEquipos, char* nombre);


void borraLista(lista_t* lista);


#endif // _LISTA_T_
