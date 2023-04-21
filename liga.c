#include "liga.h"
#include "cadena.h"

liga_t crearLiga()
{
    // creo una liga
    liga_t liga;
    //iniciar numero de equipos a 0
    liga.num_equipos=0;
	//iniciar nombre de liga a cadena vacía
    liga.nombre = NULL;
    liga.estadisticas =NULL;
    liga.equipos = NULL;
	//devolver liga iniciada
    return liga;
}

void introducirEquipoEnLiga(liga_t* liga, equipo_t* equipo)
{

    if(liga->num_equipos < NUM_EQUIPOS_LIGA){
        //introducir equipo al final de la lista de equipos
        liga->equipos[liga->num_equipos] = equipo;
        //iniciar estadisticas equipo a cero
        liga->estadisticas[liga->num_equipos].partidos_jugados = 0;
        liga->estadisticas[liga->num_equipos].derrotas = 0;
        liga->estadisticas[liga->num_equipos].victorias = 0;
        liga->estadisticas[liga->num_equipos].goles_contra = 0;
        liga->estadisticas[liga->num_equipos].goles_favor = 0;
        liga->estadisticas[liga->num_equipos].diferencia_goles = 0;
        liga->estadisticas[liga->num_equipos].empates = 0;
        liga->estadisticas[liga->num_equipos].puntos = 0;
        //actualizar numero equipos
        liga->num_equipos++;
    }
    
}
void borrarLiga(liga_t liga){
    free(liga.nombre);
    free(liga.equipos);
    free(liga.estadisticas);
}