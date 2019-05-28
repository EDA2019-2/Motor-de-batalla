bool Batalla(Personaje *this, Enemigo *that)
{
	size_t i=1;
	if(i%2==0)
	{
		a=Ataque_Enemigo( that->ataques );
		//Turno ENEMIGO
		//SIN MENU Elige un numero al azar de 1 a 3 y elige un ataque entre los ataques que conoce el enemigo
		//return Ataque
		//Los daños de ataques enemigos son fijos y no tienen rnd para extender daño
		
		size_t dano=a->daño;
		this->vida=(this->vida)-daño;
		i++;
	}
	else
	{
		Ataque* a=Ataque_Menu( this->ataques );
		//Turno JUGADOR
		//MOSTRAR MENÚ  DE ATAQUES
		//JUGADOR ELIGE ATAQUE return char Ataque Seleccionado
		if(a->Habilidad=='agilidad')
		{
			size_t tiro de dado=(rnd(101)*this->agilidad;
		}
		else if(a->Habilidad=='fuerza')
		{
			size_t tiro de dado=(rnd(101)*this->fuerza;
		}
		else if(a->Habilidad=='inteligencia')
		{
			size_t tiro de dado=(rnd(101)*this->inteligencia;
		}
		if(tiro de dado<50*(that->destreza))
		{
			i++;
			break;
		}
		size_t daño=(a->daño+rnd(a->dado)+1);
		that->vida=(that->vida)-daño;
		i++;
	}
	if(this->vida==0)
	{
		return false;
	}
	if(that->vida==0)
	{
		return true;
	}
}
