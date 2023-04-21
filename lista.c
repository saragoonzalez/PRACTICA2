#include "lista.h"
#include "cadena.h"
#include <stdio.h>
#include <stdlib.h>

// TODO usar union
lista_t crearLista(int tamLista, tipoLista_e tipo)
{
	lista_t lista;
	
	//iniciar lista vac�a
	lista.num = 0;
	//iniciar el tama�o m�ximo
	lista.maximo = tamLista;

	//iniciar el tipo
	lista.tipoLista = tipo;

	if(tipo == jugadores){
		lista.jugadores = NULL;
	}
	else if(tipo == equipos){
		lista.equipos = NULL;
	}
	else{
		lista.ligas = NULL;
	}

	//retornar la lista iniciada
	return lista;
}

void introducirEquipoEnLista(lista_t* lista, equipo_t equipo)
{
	//consultar si el tipo de lista es correcto
	if(lista->tipoLista == equipos){
		//consultar si el tama�o de la lista es mayor que el n�mero de huecos usados
		if(lista->num < lista->maximo){ //s�
			//asignar id del equipo (el mismo que su posici�n en la lista)
			equipo.identificador = lista->num;
			//introducir el equipo al final
			lista->equipos = realloc(lista->equipos,(lista->num+1) * sizeof(equipo_t) );
			//incrementar el n�mero de huecos usados
			lista->num++;
		}
		else{
			printf("ERROR, la lista de equipos está llena\n");
		}			
			
		//si no, se�alar el error
	
	}else{
		printf("ERROR, tipo de lista ha de ser equipos!\n");
	}
}

void introducirJugadorEnLista(lista_t* lista, jugador_t jugador)
{
 int capacidad = lista->capacidad;
    int tamaño = lista->tamaño;

    if (tamaño == capacidad) {
        // Redimensionar el array de la lista de jugadores
        capacidad += 10; // Aumentar la capacidad en 10 jugadores
        jugador_t* nuevo_array = realloc(lista->jugadores, capacidad * sizeof(jugador_t));

        if (nuevo_array == NULL) {
            printf("Error al redimensionar la lista de jugadores.\n");
            free(lista->jugadores);
            lista->jugadores = NULL;
            lista->capacidad = 0;
            lista->tamaño = 0;
            return;
        }
	}
}

int buscaJugador(lista_t* listaJugadores, char* nombre)
{
	int i;
	if(listaJugadores->tipoLista == jugadores){
		//por cada jugador de la lista
		for(i = 0; i<listaJugadores->num; i++){
			//si su nombre es igual al que nos pasan por par�metros
			if(comparaCadena(listaJugadores->jugadores[i].nombre,nombre)){
				//devolver su identificador
				return listaJugadores->jugadores[i].identificador;
			}
		}
		
	}
	return -1;
	
}

int buscaEquipo(lista_t* listaEquipos, char* nombre)
{
	int i;
	if(listaEquipos->tipoLista == equipos){
		//por cada equipo de la lista
		for(i = 0; i<listaEquipos->num; i++){
			//si su nombre es igual al que nos pasan por par�metros
			if(comparaCadena(listaEquipos->equipos[i].nombre,nombre)){
				//devolver su identificador
				return listaEquipos->equipos[i].identificador;
			}
		}
		
	}
	return -1;

}

void borraLista(lista_t* lista){
	for(int i=0; i<lista->num_jugadores; i++){
        borrarJugador(lista->jugadores[i]); 
    }
	free(lista->jugadores);

	for(int i=0; i<lista->num_equipos; i++){
        borrarEquipo(lista->equipos[i]); 
    }
	free(lista->equipos);
}

