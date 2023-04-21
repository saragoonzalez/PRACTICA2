#include "equipos.h"
#include "cadena.h"
#include "tipos.h"
#include <stdio.h>


equipo_t pideDatosEquipo()
{
    //iniciar identificador del equipo a 0
    equipo_t equipo;
    equipo.identificador = 0;
    //iniciar numero de jugadores a 0 (equipo vac�o)
    equipo.num_jugadores = 0;
    //pedir nombre equipo, asegurar que cabe en el array de nombres
    printf("Introduce el nombre del equipo: ");
    equipo.nombre = leeLineaDinamica();
    
    equipo.jugadores = NULL;

    //devolver equipo inicializado
    return equipo;
}

void muestraEquipo(equipo_t *equipo)
{
    int i = 0;
    //mostrar nombre equipo
    printf("Nombre del equipo: %s\n", equipo->nombre);
    
    //por cada jugador del equipo

    if(equipo->num_jugadores == 0){
        printf("El equipo aún no tiene jugadores\n");
    }
    else{
        for(i = 0; i < equipo->num_jugadores; i++){
            //mostrar jugador y sus datos pedidas en el enunciado (no son todas y tiene un formato concreto)
            //esto le pertenece a la liga, no al equipo
            muestraJugador(equipo->jugadores[i]);
        }
    }
    
}

void introduceJugadorEnEquipo(jugador_t* jugador, equipo_t* equipo)
{
    
    if(jugador->equipo != NULL){
        printf("Este jugador ya pertenece al %s\n", jugador->equipo->nombre);
    }
    else if(equipo->num_jugadores < NUM_JUGADORES){
        //el equipo almacenado dentro del jugador apunta al equipo que nos pasan
        jugador->equipo = equipo;
        //el jugador se introduce al final de la lista de equipos,
        equipo->jugadores[equipo->num_jugadores] = jugador;
        //actualizar n�mero de jugadores
        equipo->num_jugadores++;
    }
    else{
        printf("El equipo está lleno\n");
    }
    
}
void borrarEquipo(equipo_t equipo) {
    free(equipo.nombre);
    free(equipo.jugadores);
}
