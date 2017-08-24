#ifndef JUEGO_H
#define JUEGO_H

#include <conio.h>
#include <iostream>

#include "Comida.h"
#include "Constantes.h"
#include "Funciones.h"
#include "Mapa.h"
#include "Snake.h"

class Juego {
private:
	bool  abajo;
	bool  arriba;
	bool  derecha;
	bool  izquierda;
	bool  game_over;
	const int ABAJO     = 80;
	const int ARRIBA    = 72;
	const int DERECHA   = 77;
	const int IZQUIERDA = 75;
	const int ESCAPE    = 27;
	int   ultima_tecla_pulsada;
	int   ultimo_movimiento;
	Comida* comida;
	Mapa tablero;
	Snake* snake;
protected:
public:
	Juego();
	~Juego();
	
	void Borrar_Final_Serpiente();
	void Comer();
	void Info_Teclas();
	void Jugar();
	
	void Modificar_Mapa(int i, int j, char c);
	void Dibujar_Mapa();
};

#endif

