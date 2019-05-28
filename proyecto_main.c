#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "personaje.h"

int main(){

    srand(time (0));

    char nombre[50];
    printf("Bienvenido, Introduce tu nombre: ");
    scanf("%[^\n]", nombre);

    Personaje* Player1 = Crear_Personaje( nombre );
	Personaje* Enemigo1 = Crear_Enemigo( );
    if ( Batalla( Player1, Enemigo1 ) )
    {
        printf("Ganaste\n");
    }else
    {
        printf("Perdiste\n");
    }

	Borrar_Personaje( Player1 );
    Borrar_Personaje( Enemigo1 );
	return 0;
}
