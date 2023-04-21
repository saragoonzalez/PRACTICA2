#include "lista.h"
#include "jugadores.h"
#include "equipos.h"
#include "cadena.h"
#include "liga.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menuOpcionesMostrarDatos() {
	printf("Introduzca una opción:\n");
	printf("1-Mostrar Jugadores\n");
	printf("2-Mostrar Equipos\n");
	printf("3-Mostrar Liga\n");

}
void menuOpcionesPrincipal()
{
	printf("Introduzca una opción:\n");
	printf("1-Crear nuevo Jugador\n");
	printf("2-Crear nuevo Equipo\n");
	printf("3-Añadir jugadores a un equipo\n");
	printf("4-Crear nueva Liga\n");
	printf("5-Mostrar datos almacenados\n");
	printf("6-Salir\n");

}

int main(int argc, char*argv[])
{

	//iniciar lista jugadores vacía
	// TODO tamaño?
	lista_t listaJugadores = crearLista(10,jugadores);
	//iniciar lista equipos vacía
	lista_t listaEquipos = crearLista(10,equipos);
	//iniciar liga vacía
	liga_t liga = crearLiga();

	// Variables auxiliares
	char* nombre;
	jugador_t j;
	equipo_t e;
	int opcion = 0, opcionDatos = 0;
	int posicionJ, posicionE,numEquipos;
	int i;
	// -----------------------

	//mientras no salir
	do{
		
		//menú opciones
		printf("----------------------------------------\n");
		menuOpcionesPrincipal();
		//pedir opcion
		printf("Introduce una opcion: ");
		scanf("%d",&opcion);
		//ver tipo de opción:
		switch(opcion){
			//opción nuevo jugador
			case 1:
				//pedir datos de jugador
				j = pideDatosJugador();
				//introducir en lista
				introducirJugadorEnLista(&listaJugadores, j);
				break;
			//opción nuevo equipo
			case 2:
				//pedir datos
				e = pideDatosEquipo();
				//introducir en lista
				introducirEquipoEnLista(&listaEquipos, e);
				break;
			//opción añadir jugadores a equipo
			case 3:
				//buscar equipo
				if(listaEquipos.num == 0){
					printf("No hay equipos definidos\n");
				}
				else if(listaJugadores.num == 0){
					printf("No hay jugadores definidos\n");
				}
				else{
					printf("Dame el nombre del equipo: ");
				nombre = leeLineaDinamica(TAM_NOMBRE);
				posicionE = buscaEquipo(&listaEquipos, nombre);
				//repetir mientras no encuentre el equipo
				while(posicionE == -1){
					//pedir nombre
					printf("No existe ese equipo\nDame el nombre del equipo: ");
					nombre = leeLineaDinamica(TAM_NOMBRE);
					//buscar nombre en lista de equipos
					posicionE = buscaEquipo(&listaEquipos, nombre);
				}//si no existe, repetir
				free(nombre);
				//buscar jugador
				printf("Dame el nombre del jugador: ");
				nombre = leeLineaDinamica(TAM_NOMBRE);
				posicionJ = buscaJugador(&listaJugadores, nombre);
				
				while(posicionJ == -1){
					//pedir nombre
					printf("No existe ese jugador\nDame el nombre del jugador: ");
					nombre = leeLineaDinamica(TAM_NOMBRE);
					//buscar nombre en lista de jugadores
					posicionJ = buscaJugador(&listaJugadores, nombre);
				}//si no existe, repetir
				free(nombre);
				//introducir jugador en equipo
				introduceJugadorEnEquipo(&listaJugadores.jugadores[posicionJ], &listaEquipos.equipos[posicionE]);
				}
				
				break;
			//opción nueva liga
			case 4:	
				//pedir nombre liga
				printf("Dame el nombre de la liga: ");
				liga.nombre = leeLineaDinamica(TAM_NOMBRE);

				//añadir equipos
				//pedir numero equipos
				printf("Cuantos equipos vas a introducir: ");
				scanf("%d",&numEquipos);
				//para cada equipo en número de equipos
				for(i = 0; i<numEquipos; i++){
					//repetir mientras no se encuentre el equipo
					do{
						printf("Dame el nombre del equipo: ");
						nombre = leeLineaDinamica(TAM_NOMBRE);
						posicionE = buscaEquipo(&listaEquipos, nombre);
						free(nombre);
					}while(posicionE == -1); //si no existe, repetir pedir nombre
					//introducir equipo en liga
					introducirEquipoEnLiga(&liga, &listaEquipos.equipos[posicionE]);
				}
				break;	
							
								
			//opción mostrar datos almacenados				
			case 5:
				//mostrar menú para seleccionar datos
				menuOpcionesMostrarDatos();
				// 1= mostrar jugadores
				// 2= mostrar equipos
				// 3= mostrar liga
				//leer opción
				printf("Introduce una opcion: ");
				scanf("%d",&opcionDatos);
				//ver tipo de opción
				switch (opcionDatos){
					case 1://opción mostrar lista jugadores
						//por cada jugador
						for(i = 0; i<listaJugadores.num; i++){
							muestraJugador(&listaJugadores.jugadores[i]);
						}
						break;
					//opción mostrar equipos
					case 2:
						//por cada equipo
						for(i = 0; i<listaEquipos.num; i++){
							//mostrar su nombre, estadísticas y nombre de jugadores con estadísticas de jugador
							muestraEquipo(&listaEquipos.equipos[i]);
						}
						break;
					//opción mostrar liga
					case 3:
						//por cada equipo
						if( comparaCadena(liga.nombre,"") == 1){
							printf("La liga no tiene nombre\n");
						}
						if(liga.num_equipos == 0){
							printf("La liga no tiene equipos\n");
						}

						for(i = 0; i < liga.num_equipos; i++){
							//mostrar equipo
							muestraEquipo(liga.equipos[i]);
							//mostrar estadisticas de equipo
						}
					default:
						printf("Opcion erronea, volviendo al menu\n");
						break;
				}						
			    break;
			//opción salir
			//acabar bucle "mientras no salir"
			case 6:
				printf("Hasta la próxima\n");
				break;
			default:
				printf("Opcion erronea, volviendo al menu\n");	
		}
	}while(opcion != 6);
	
	//liberar memoria (si es necesario)
	//acabar programa



    liga_t liga;
    int num_equipos;

    printf("Introduce el número de equipos de la liga: ");
    scanf("%d", &num_equipos);

  
    crearLiga(&liga, num_equipos);

    introducirEquiposEnLiga(&liga);

 
    crearCalendarioParaLiga(&liga);


    mostrarDatosLiga(liga);
    mostrarCalendario(liga);

   
    borrarLiga(&liga);
    borrarCalendario(&liga);

    return 0;














}
