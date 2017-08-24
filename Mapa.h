#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include "Casilla.h"
#include "Constantes.h"
#include "Snake.h"

class Mapa {
	
	private:
		Casilla mapa[ALTO][ANCHO];
		
	protected:
		
	public:
		Mapa();
		~Mapa();
		
		void Set_Dibujo_Casilla(int i, int j, char c);
		void Dibujar();
};

#endif

