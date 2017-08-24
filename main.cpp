#include<ctime>
#include<iostream>

#include <windows.h>
#include "Funciones.h"
#include "Juego.h"
#include "Snake.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	srand(time(NULL));
	Juego snake;
	snake.Jugar();
	//Funciones::Marco();
	
	/*Snake s('A', 'C', 5, 5);
	while(true)
	{
		s.Mover(80);
		s.Dibujar();
	}*/
	return 0;
}

