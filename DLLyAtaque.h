#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct
{
	char nombre[20];
	int dano;
	unsigned int dado;
	int habilidad;
}Ataque;

typedef struct Node
{
	struct Node *next;
	struct Node *prev;
	Ataque guajolocombo;
}Node;

typedef struct
{
	Node *first;
	Node *last;
	Node *cursor;
    size_t len;
}DLL;

void newAtaque( DLL*this );
DLL* DLL_New();
Ataque DLL_Peek( DLL* this );
void DLL_CursorFirst( DLL *this );
void DLL_CursorNext( DLL *this );
void DLL_CursorPrev( DLL *this );
bool DLL_IsEmpty( DLL* this );
void DLL_MakeEmpty( DLL* this );
size_t DLL_Len( DLL* this );
Ataque Ataque_Menu( DLL* this );
Ataque Ataque_Enemigo ( DLL* lista );
void DLL_Delete( DLL* this );
