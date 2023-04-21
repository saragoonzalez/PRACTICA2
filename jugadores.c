
#include <stdlib.h>
#include <stdio.h>
#include "cadena.h"
#include "jugadores.h"
#include "tipos.h"

tipoJugador_e buscaTiposJugador(const char* tipoJugador){
	
	//crear array de cadenas v�lidas: "portero", "defensa", "medio", "delantero"
	char posiciones[4][10] = {"portero", "defensa", "medio", "delantero"};
	//comparar tipoJugador con las cadenas v�lidas
		//si es igual a alguna de las cadenas v�lidas
			//Devolver el valor enumerado equivalente
	//devolver error si no se ha encontrado el valor enumerado equivalente (cadena no v�lida)
	int i;
	for(i = 0; i < 4; i++ ){
		if(comparaCadena(tipoJugador,posiciones[i]) == 1){
			return i;
		}
	}
	return -1;
}

jugador_t pideDatosJugador()
{	
	tipoJugador_e tipoIntroducido;
	char posicion[10];
	int ok; // lo uso para validar la posicion
	jugador_t jugador;
	//deja sus estad�sticas inicializadas a 0
	jugador.estadisticasJugador.asistencias = 0;
	jugador.estadisticasJugador.balones_perdidos = 0;
	jugador.estadisticasJugador.goles_marcados = 0;

    jugador.identificador = 0;
	//iniciar su equipo a NULL
	jugador.equipo = NULL;
	//pedir nombre
	printf("Introduce el nombre del jugador: ");
	jugador.nombre = leeLineaDinamica();
	fflush(stdin); // limpiar la entrada
	printf("Introduce los apellidos del jugador: ");
	jugador.apellidos = leeLineaDinamica();
	fflush(stdin);

	ok = 0;
	do{
		printf("Posición del jugador (portero,defensa, medio, delantero): ");
		scanf("%s", posicion);
		tipoIntroducido = buscaTiposJugador(posicion);
	}while(tipoIntroducido == -1); // doy vueltas hasta que tenga un valor correcto
	jugador.tipo = tipoIntroducido;
	//pedir nombre, asegurar que cabe en el array "Nombre"
	//pedir DNI, asegurar que cabe en el array "Dni"
	fflush(stdin);
	printf("Introduce el dni del jugador: ");
	jugador.dni = leeLineaDinamica();
	// no deberia de hacerlo con scanf  si no con lee linea 
	
	//pedir Telefono, asegurar que cabe en el array "Telefono"
	printf("Introduce telefono del jugador: ");
	jugador.telefono = leeLineaDinamica();
	
	//devolver jugador inicializado
	return jugador;
}

void muestraJugador(jugador_t* jugador) {
	//mostrar datos privados de jugador, nombre, posici�n, estad�sticas
	printf("Datos del jugador:\n");
	printf("Nombre y apellidos: %s %s\n", jugador->nombre, jugador->apellidos);
	printf("Telefono: %s\nDNI: %s\n", jugador->telefono, jugador->dni);
	switch(jugador->tipo){
		case delantero:
			printf("Su posición es delantero\n");
			break;
		case defensa:
			printf("Su posición es defensa\n");
			break;
		case portero:
		printf("Su posición es portero\n");
			break;
		case medio:
		printf("Su posición es medio\n");
			break;
	}
}

void borrarJugador(jugador_t jugador) {
    free(jugador.nombre);
    free(jugador.dni);
    free(jugador.telefono);
}





void crearCalendarioParaLiga(liga_t* liga) {
    // Verificar que hay suficientes equipos y que el número de equipos es par
    if (liga->num_equipos< 4 || liga->num_equipos % 2 != 0) {
        printf("La liga no tiene suficientes equipos o el número de equipos es impar.\n");
        return;
    }

    int numJornadas = liga->num_equipos - 1;
    int numPartidosPorJornada = liga->num_equipos/ 2;
    int posCalendario = 0;
    int** calendario = malloc(numJornadas * sizeof(int*));

    // Crear matriz de calendario
    for (int i = 0; i < numJornadas; i++) {
        calendario[i] = malloc(numPartidosPorJornada * sizeof(int));
    }

    // Asignar equipos a las jornadas
    for (int i = 0; i < numJornadas / 2; i++) {
        for (int j = 0; j < numPartidosPorJornada; j++) {
            calendario[posCalendario][j] = i + j;
            if (j == 0) {
                calendario[posCalendario][j] = i;
            } else if (j == numPartidosPorJornada - 1) {
                calendario[posCalendario][j] = liga->num_equipos - i - 1;
            }
        }
        posCalendario++;
        // Rotar equipos
        int temp = calendario[posCalendario - 1][1];
        for (int j = 1; j < numPartidosPorJornada - 1; j++) {
            calendario[posCalendario - 1][j + 1] = calendario[posCalendario - 1][j];
        }
        calendario[posCalendario - 1][1] = calendario[posCalendario - 1][0];
        calendario[posCalendario - 1][0] = temp;
    }

    // Asignar jornadas al calendario de la liga
    liga->calendario = calendario;
    liga->numJornadas = numJornadas;
}

    // Calcular el número de días por semana
    int diasPorSemana = floor(liga->num_equipos/ 2);
    
    // Calcular el número de semanas
    int numSemanas = liga->num_equipos- 1;
    
    // Calcular el número de partidos por día
    int partidosPorDia = liga->num_equipos / 2;
    
    // Inicializar matriz de partidos
    int partidos[liga->num_equipos][liga->num_equipos];
    memset(partidos, 0, sizeof(partidos));
    
    // Generar los partidos de cada día
    for (int semana = 0; semana < numSemanas; semana++) {
        // Generar los partidos de cada día
        for (int dia = 0; dia < diasPorSemana; dia++) {
            // Obtener los equipos que juegan ese día
            int equipoLocal = dia + semana;
            int equipoVisitante = (liga->num_equipos - 1) - dia + semana;
            
            // Rotar los equipos para generar los partidos
            for (int partido = 0; partido < partidosPorDia; partido++) {
                partidos[dia + partido][(equipoLocal + partido) % liga->num_equipos] = 1;
                partidos[dia + partido][(equipoVisitante - partido + liga->num_equipos) % liga->num_equipos = 1;
            }
        }
