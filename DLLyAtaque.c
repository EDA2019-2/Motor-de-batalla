#include "DLLyAtaque.h"

static Node* newNode( Ataque _data )
{
	Node* n = (Node*) malloc( sizeof( Node ) );
	if( n ){
		n->guajolocombo = _data;
		n->next = NULL;
		n->prev = NULL;
	}
	return n;
}

static void reset( DLL* this )
{
	this->first = this->last = this->cursor = NULL;
	this->len = 0;
}

void newAtaque( DLL*this )
{
	FILE* ptr_file;
    char _nombre[20];
	int _dano, _dado, type, _habilidad;

	type = ((rand() % 5) + 1);


	switch (type) {
		case 1:
			ptr_file = fopen( "Habilidad1.txt", "r" );
			break;
		case 2:
			ptr_file = fopen( "Habilidad2.txt", "r" );
			break;
		case 3:
			ptr_file = fopen( "Habilidad3.txt", "r" );
			break;
		case 4:
			ptr_file = fopen( "Habilidad4.txt", "r" );
			break;
        case 5:
			ptr_file = fopen( "Habilidad5.txt", "r" );
			break;
        case 6:
			ptr_file = fopen( "Habilidad6.txt", "r" );
			break;
		default:
			break;
	}

	fscanf( ptr_file, "%[^\n]\n%d\t%d\t%d", _nombre, &_habilidad, &_dano, &_dado );
	fclose(ptr_file);

    Ataque _atack;
    strcpy( _atack.nombre, _nombre );
    _atack.habilidad = _habilidad;
    _atack.dano = _dano;
    _atack.dado = _dado;

    Node* n = newNode( _atack );

    if( n ){
		if( DLL_IsEmpty( this ) ){
			this->first = n;
            this->last = n;
			this->len = 1;
		} else {
			this->last->next = n;
			n->prev = this->last;
			this->last = n;
			++this->len;
		}
	}
}

DLL* DLL_New()
{
    DLL* list = (DLL*) malloc( sizeof( DLL ) );
	if( list ){
		reset( list );
	}
	return list;
}

Ataque DLL_Peek( DLL* this )
{
    assert( this );

    return this->cursor->guajolocombo;
}

void DLL_CursorFirst( DLL *this )
{
    assert( this );
	this->cursor = this->first;
}

void DLL_CursorNext( DLL *this )
{
    assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->next;
	}
}

void DLL_CursorPrev( DLL *this )
{
    assert( this );
	if( this->cursor != NULL ){
		this->cursor = this->cursor->prev;
	}
}

bool DLL_IsEmpty( DLL* this )
{
	assert( this );
	return this->first == NULL;
}

void DLL_MakeEmpty( DLL* this )
{
	assert( this );
	while( NULL != this->first){
		Node* tmp = this->first->next;
		free( this->first );
		this->first = tmp;
	}
	reset( this );
}

size_t DLL_Len( DLL* this )
{
    assert( this );

    return this->len;
}

Ataque Ataque_Menu ( DLL* lista )
{
    int eleccion = 0;
    Ataque ataque;
    int n = 1;

    do{
        if ( n == 1 ){
            DLL_CursorFirst( lista );
        }else{ DLL_CursorNext( lista ); }
        ataque = DLL_Peek( lista );

        printf( "-%d-\t%s\n", n, ataque.nombre );
        n++;


    }while( n-1 < DLL_Len( lista ) );

    do{
    printf( "Introduzca eleccion\n");
    scanf("%d", &eleccion);
    }while ( eleccion >= n || eleccion <= 0 );

    for ( int i = 0 ; i < ((n-1)-eleccion); i++ )
    {
        DLL_CursorPrev( lista );
    }
    ataque = DLL_Peek( lista );

    return ataque;

}

Ataque Ataque_Enemigo ( DLL* lista )
{
    Ataque ataque;
    int n = rand( ) % DLL_Len( lista );

    DLL_CursorFirst( lista );
    for (size_t i = 0; i < n; i++)
    {
        DLL_CursorNext( lista );
    }
    ataque = DLL_Peek( lista );


    return ataque;

}

void DLL_Delete( DLL* this )
{
    if( this ){
		DLL_MakeEmpty( this );
		free( this );
	}
}
