#include "cadena.h"
#include <string.h> // strcmp(c1,c2) 
#include <stdlib.h>
#include <stdio.h>
int comparaCadena(const char* c1,const  char* c2) {
	//usar método "comparaCadena" visto en clase
	// strcmp(c1,c2) devuelve 0 si las cadenas son iguales, negativo si la primera cadena es menor, y positivo si es mayor
	// STRing CoMPare
	if(strcmp(c1,c2) == 0){
		return 1;
	}
	else{
		return 0;
	}
}
char* leeLineaDinamica(){
    char* linea=NULL;
    int i=0;
	fflush(stdin);
    do{
        linea=realloc(linea,(i+1)*sizeof(char));
        linea[i]=getchar(); // getchar() me devuelve un caracter escrito por la terminal 
        i++;
    }while (linea[i-1]!='\n');
    linea [i-1]='\0'; // sustituyo el \n por \0
    return linea;
}