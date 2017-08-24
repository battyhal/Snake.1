#include "Mapa.h"

Mapa::Mapa() 
{
	/*for(int i = 0; i < ALTO; i++)
	{
		for(int j = 0; j < ANCHO; j++)
		{
			mapa[j][i].Set_Dibujo(' ');
		}
	}*/
}

void Mapa::Set_Dibujo_Casilla(int i, int j, char c)
{			
	mapa[j][i].Set_Dibujo(c);			
}

Mapa::~Mapa() {}

void Mapa::Dibujar()
{	
	char bases = 205;
	char paredes = 186;
	char esquina_sup_dcha = 187; 
	char esquina_inf_dcha = 188;
	char esquina_inf_izq = 200;
	char esquina_sup_izq = 201;
	std::cout << "\n ";
	for(int j = 0; j < ANCHO; j++)
	{
		std::cout << bases;
		for(int k = 0; k < ALTO; k++)
		{					
			if(j == 0 && k == 0)
				std::cout << esquina_sup_izq;
			if(j == 0 && k == ALTO - 1)
				std::cout << esquina_sup_dcha;
			if(j == ANCHO - 1 && k == 0)
				std::cout << esquina_inf_izq;
			if(j == ANCHO - 1 && k == ALTO - 1)
				std::cout << esquina_inf_dcha;
			if(k == 0 || k == ALTO - 1)
				std::cout << paredes;
		}
		std::cout << "\n";
	}
}
