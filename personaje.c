#include "personaje.h"

Personaje* Crear_Personaje( char* name )
{
	Personaje* p = ( Personaje* ) malloc( sizeof( Personaje) );
	if( p ){
		p->nombre = name;
		p->agilidad = 10;
		p->fuerza = 10;
		p->inteligencia = 10;
		p->vida_total = 100;
		p->vida = p->vida_total;
		p->ataques = DLL_New();
		newAtaque( p->ataques );
		newAtaque( p->ataques );
	}
	return p;
}

Personaje* Crear_Enemigo( )
{
	srand(time (0));

	FILE* ptr_file;
	char nombre[20];
	int vida, fuerza, intel, agi, type;

	type = ((rand() % 3) + 1);


	switch (type) {
		case 1:
			ptr_file = fopen( "Enemigo1.txt", "r" );
			break;
		case 2:
			ptr_file = fopen( "Enemigo2.txt", "r" );
			break;
		case 3:
			ptr_file = fopen( "Enemigo3.txt", "r" );
			break;
		case 4:
			ptr_file = fopen( "Enemigo4.txt", "r" );
			break;
		default:
			break;
	}

	fscanf( ptr_file, "%[^\n]%d\t%d\t%d\t%d", nombre, &agi, &vida, &fuerza, &intel);
	fclose(ptr_file);

	Personaje* p = ( Personaje* ) malloc( sizeof( Personaje) );
	if( p ){
		p->nombre = nombre;
		p->agilidad = agi;
		p->vida_total = vida;
		p->vida = p->vida_total;
		p->fuerza = fuerza;
		p->inteligencia = intel;
		p->ataques = DLL_New();
		newAtaque( p->ataques );
		newAtaque( p->ataques );
	}
	return p;
}

void Borrar_Personaje( Personaje* this )
{
	if( this ){
		DLL_Delete( this->ataques );
		free( this );
	}
}

void Mejora_Personaje( Item PM, Personaje* this )
{
    system("cls");
	while( PM > 0 ){
		char opc; //////////////////
		printf("\n\t\t%s\n",Personaje_Nombre( this ) );
        printf(" Vida: %d\n",Personaje_Vida( this ) );
        printf(" Agilidad: %d\n",Personaje_Agilidad( this ) );
        printf(" Fuerza: %d\n",Personaje_Fuerza( this ) );
        printf(" Inteligencia: %d\n",Personaje_Inteligencia( this ) );
		printf( "\n Ingresa la habilidad que deseas mejorar: \n"
		        " 1) Vida \n"
				" 2) Agilidad \n"
				" 3) Fuerza \n"
				" 4) Inteligencia \n"
				" \n Opcion seleccionada: "
				);
		scanf("%c", &opc);
		switch( opc-48 ){
			case 1:
				this->vida += 10;
				break;
			case 2:
			    this->agilidad += 1;
				break;
			case 3:
			    this->fuerza += 1;
				break;
			case 4:
			    this->inteligencia += 1;
			    break;

			default:
			 		PM++;
					break;
		}
		PM--;
		system("cls");
		printf("\n �Te quedan %d puntos de mejora!\n", PM);
	}
	printf("\n\t\t%s\n",Personaje_Nombre( this ) );
    printf(" Vida: %d\n",Personaje_Vida( this ) );
    printf(" Agilidad: %d\n",Personaje_Agilidad( this ) );
    printf(" Fuerza: %d\n",Personaje_Fuerza( this ) );
    printf(" Inteligencia: %d\n",Personaje_Inteligencia( this ) );
}

char* Personaje_Nombre( Personaje* this )
{
	return this->nombre;
}

int Personaje_Vida( Personaje* this )
{
	return this->vida;
}

int Personaje_Fuerza( Personaje* this )
{
	return this->fuerza;
}

int Personaje_Inteligencia( Personaje* this )
{
	return this->inteligencia;
}

int Personaje_Agilidad( Personaje* this )
{
	return this->agilidad;
}

bool Batalla(Personaje *this, Personaje *that)
{
	size_t tiro_de_dado;
	size_t i=1;
	Ataque a;
	bool resultado;
	while( this->vida > 0 && that->vida > 0 ){
		if(i%2==0)
		{
			a=Ataque_Enemigo( that->ataques );
			//Turno ENEMIGO
			//SIN MENU Elige un numero al azar de 1 a 3 y elige un ataque entre los ataques que conoce el enemigo
			//return Ataque
			//Los daños de ataques enemigos son fijos y no tienen rnd para extender daño

			int ability = a.habilidad;
			if(ability==1)
			{
				tiro_de_dado=(rand() % 101)*(this->agilidad);
			}
			else if(ability==2)
			{
				tiro_de_dado=(rand() % 101)*(this->fuerza);
			}
			else if(ability==3)
			{
				tiro_de_dado=(rand() % 101)*(this->inteligencia);
			}
			if(tiro_de_dado<50*(ability))
			{
				i++;
			}

			size_t _dano=a.dano;
			this->vida=(this->vida)-_dano;
			i++;
		}
		else
		{
			printf("Tu vida: %d/%d\tVida enemigo: %d/%d\n", this->vida, this->vida_total, that->vida, that->vida_total);
			a=Ataque_Menu( this->ataques );
			//Turno JUGADOR
			//MOSTRAR MENÚ  DE ATAQUES
			//JUGADOR ELIGE ATAQUE return char Ataque Seleccionado

			int ability = a.habilidad;
			if(ability==1)
			{
				tiro_de_dado=(rand() % 101)*(this->agilidad);
			}
			else if(ability==2)
			{
				tiro_de_dado=(rand() % 101)*(this->fuerza);
			}
			else if(ability==3)
			{
				tiro_de_dado=(rand() % 101)*(this->inteligencia);
			}
			if(tiro_de_dado<50*(ability))
			{
				i++;
			}
			size_t _dano=(a.dano+(rand() % a.dado)+1);
			that->vida=(that->vida)-_dano;
			i++;
		}
	}

	if(this->vida<=0)
	{
		resultado = false;
	}
	if(that->vida<=0)
	{
		resultado = true;
	}

	return resultado;
}
