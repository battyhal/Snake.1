#ifndef COMIDA_H
#define COMIDA_H

#include <cstdlib>
#include <iostream>
#include <math.h>

#include "Constantes.h"
#include "Funciones.h"

class Comida {
private:
	bool viva;
	char dibujo;
	int x;
	int y;
protected:
public:
	Comida(char c, int i, int j);
	~Comida();
	
	bool Get_Viva();
	char Get_Dibujo();
	int  Get_X();
	int  Get_Y();
	void Set_Viva(bool b);
	
	void Dibujar();
};

#endif

