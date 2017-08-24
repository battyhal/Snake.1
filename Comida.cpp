#include "Comida.h"

Comida::Comida(char c, int i, int j) 
{
	viva = true;
	dibujo = '*';
	x = i;
	y = j;
}

Comida::~Comida() {}

bool Comida::Get_Viva() 	  { return viva; }
char Comida::Get_Dibujo()     { return dibujo; }
int  Comida::Get_X()		  { return x; }
int  Comida::Get_Y()		  { return y; }
void Comida::Set_Viva(bool b) { viva = b; }

void Comida::Dibujar()
{
	Funciones::Goto_XY(x, y);
	std::cout << dibujo;
}
