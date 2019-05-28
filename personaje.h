#ifndef  Personaje_INC
#define  Personaje_INC

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>

#include "DLLyAtaque.h"

typedef int Item;
typedef Item* ItemPtr;

typedef struct Personaje
{
	char* nombre;
	int vida;
	int vida_total;
	int fuerza;
	int inteligencia;
	int agilidad;
	DLL *ataques;
} Personaje;


Personaje* Crear_Personaje( char* name );
Personaje* Crear_Enemigo( );
void Borrar_Personaje( Personaje* this );
void Mejora_Personaje( Item PM, Personaje* this );
char* Personaje_Nombre( Personaje* this );
Item Personaje_Vida( Personaje* this );
Item Personaje_Fuerza( Personaje* this );
Item Personaje_Inteligencia( Personaje* this );
Item Personaje_Agilidad( Personaje* this );
bool Batalla(Personaje *this, Personaje *that);




#endif
