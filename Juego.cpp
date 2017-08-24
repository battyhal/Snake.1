#include "Juego.h"

Juego::Juego() 
{
	system("cls");
	Info_Teclas();
	//mapa.Dibujar_Marco();
	int max = ANCHO;
	int min = 0;
	int aleatorioX = 0;
	int aleatorioY = 0;
	do
	{
		aleatorioX = rand() % (max - min) + min;
		aleatorioY = rand() % (max - min) + min;
	}while(aleatorioX > ANCHO - 1 || aleatorioY > ALTO - 1
		   || aleatorioX < 2 || aleatorioY < 2);
	comida = new Comida('*', aleatorioX, aleatorioY);
	
	max = 5;
	min = 1;
	int aleatorio = 0;
	do
	{
		aleatorio = rand() % (max - min) + min;
	}while(aleatorio > 4 || aleatorio < 1);
	switch(aleatorio)
	{
	case 1:
	{
		ultimo_movimiento = ABAJO;
	}
	break;
	case 2:
	{
		ultimo_movimiento = ARRIBA;
	}
	break;
	case 3:
	{
		ultimo_movimiento = DERECHA;
	}
	break;
	case 4:
	{
		ultimo_movimiento = IZQUIERDA;
	}
	break;
	} // Fin switch
	snake = new Snake('<', 'H', ALTO / 4, ANCHO / 4);
	
	abajo = false;
	arriba = false;
	derecha = false;
	izquierda = true;
	game_over = false;
	//ultima_tecla_pulsada = snake->Get_Ultimo_Movimiento();
}

Juego::~Juego() 
{
	comida = 0;
	snake  = 0;
	delete comida;
	delete snake;
}

void Juego::Borrar_Final_Serpiente()
{
	Funciones::Goto_XY(snake->Get_Casilla(snake->Get_Partes_Cuerpo()-1).Get_X()
					   , snake->Get_Casilla(snake->Get_Partes_Cuerpo()-1).Get_Y());
	std::cout << ' ';
}

void Juego::Comer()
{
	if(snake->Get_Casilla(0).Get_X() == comida->Get_X() && snake->Get_Casilla(0).Get_Y() == comida->Get_Y())
	{
		snake->Crecer();
		comida->Set_Viva(false);
		int max = ANCHO;
		int min = 0;
		int aleatorioX = 0;
		int aleatorioY = 0;
		do
		{
			aleatorioX = rand() % (max - min) + min;
			aleatorioY = rand() % (max - min) + min; 
		} while(aleatorioX > ANCHO - 2 || aleatorioY > ALTO - 4
				|| aleatorioX < 2 || aleatorioY < 4);
		comida = 0;
		comida = new Comida('*', aleatorioX, aleatorioY);
	}
}

void Juego::Info_Teclas()
{
	Funciones::Goto_XY(ANCHO + 3, 2);
	std::cout << " Arriba    : Cursor ARRIBA";
	Funciones::Goto_XY(ANCHO + 3, 3);
	std::cout << " Abajo     : Cursor ABAJO";
	Funciones::Goto_XY(ANCHO + 3, 4);
	std::cout << " Izquierda : Cursor IZQUIERDA";
	Funciones::Goto_XY(ANCHO + 3, 5);
	std::cout << " Derecha   : Cursor DERECHA";
	Funciones::Goto_XY(ANCHO + 3, 6);
	std::cout << " Salir     : ESCAPE";
}

void Juego::Jugar()
{	
	Funciones::No_Cursor();
	while(!game_over)
	{
		//snake->Mover(ultimo_movimiento);
		if(kbhit())
		{
			char tecla = getch();
			if(tecla == ESCAPE)
			{
				game_over = true;
				//return false;
			}
			if(tecla == ABAJO && snake->Get_Casilla(0).Get_Y() + 1 <= ALTO + 1)
			{
				if(abajo)
				{
					// Para borrar la última casilla de la serpiente
					Borrar_Final_Serpiente();
					arriba    = false;
					derecha   = true;
					izquierda = true;
					snake->Mover(ABAJO);
					ultimo_movimiento = ABAJO;
				}
			}
			if(tecla == ARRIBA && snake->Get_Casilla(0).Get_Y() - 1 >= 0)
			{
				if(arriba)
				{
					Borrar_Final_Serpiente();
					abajo     = false;
					derecha   = true;
					izquierda = true;
					snake->Mover(ARRIBA);
					ultimo_movimiento = ARRIBA;
				}
			}
			if(tecla == DERECHA && snake->Get_Casilla(0).Get_X() + 1 <= ANCHO + 1)
			{
				if(derecha)
				{
					Borrar_Final_Serpiente();
					abajo     = true;
					arriba    = true;
					izquierda = false;
					snake->Mover(DERECHA);
					ultimo_movimiento = DERECHA;
				}
			}
			if(tecla == IZQUIERDA && snake->Get_Casilla(0).Get_X() - 1 >= 0)
			{
				if(izquierda)
				{
					Borrar_Final_Serpiente();
					abajo   = true;
					arriba  = true;
					derecha = false;
					snake->Mover(IZQUIERDA);
					ultimo_movimiento = IZQUIERDA;
				}
			}
		} // Fin if(kbhit())
		Comer();
		//Dibujar_Mapa();
		comida->Dibujar();
		snake->Dibujar();
		//Sleep(50);
	}
}

void Juego::Modificar_Mapa(int i, int j, char c)
{
	tablero.Set_Dibujo_Casilla(i, j, c);
}

void Juego::Dibujar_Mapa()
{
	tablero.Dibujar();
}
