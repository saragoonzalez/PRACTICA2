#include "calendario.h"

void crearCalendarioParaLiga(liga_t* liga)
{
	//revisar si hay al menos 4 equipos y que el n�mero de equipos sea par
		//si no lo es, mostrar error por terminal y no hacer nada
	
	//si hay n�mero suficiente de equipos
		//n�mero de semanas= equipos -1
		//n�mero de d�as por semana
		//reservar la memoria para la tabla de emparejamientos
		//reservar n�mero de semanas
		//por cada semana
			//reservar n�mero de d�as por semana para esa semana
			//por cada d�a de esa semana
				//reservar un emparejamiento (2 integers) para ese d�a de esa semana
		
		//rellenar el primer equipo del emparejamiento
		//contador=0
		//por cada jornada de la tabla
			//primer equipo de jornada=contador
			//si contador == (numeroEquiposEnLiga-1) 
				//contador=0
		//rellenar el segundo equipo de la primera columna de jornadas con el �ltimo equipo
		//rellenar el resto de jornadas con un contador inverso de equipos, saltando el �ltimo equipo
}		
		

void mostrarCalendario(liga_t liga)
{
	//primera fila, mostrar �ndice de los d�as de la semana que se jugar�
	//siguientes filas, por cada semana
		//por cada d�a de esa semana
			//mostrar el nombre de los dos equipos que jugar�n
}



void borrarCalendario(liga_t* liga)
 {
    // Liberar la memoria reservada para el array de emparejamientos
    for (int i = 0; i < liga->numSemanas; i++) {
        for (int j = 0; j < liga->numDias; j++) {
            free(liga->calendario[i][j]);
        }
        free(liga->calendario[i]);
    }
    free(liga->calendario);
    
    // Liberar la memoria reservada para el array de días de semana
    for (int i = 0; i < liga->numSemanas; i++) {
        free(liga->dias_semana[i]);
    }
    free(liga->dias_semana);
    
    // Liberar la memoria reservada para las semanas
    for (int i = 0; i < liga->numSemanas; i++) {
        free(liga->semanas[i]);
    }
    free(liga->semanas);
    
    // Reiniciar el calendario en la liga
    liga->numSemanas = 0;
    liga->numDias = 0;
    liga->dias_semana = NULL;
    liga->semanas = NULL;
    liga->calendario = NULL;
}
