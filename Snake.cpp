#include "Snake.h"

Snake::Snake(char c, char id, int x, int y) 
{
	// Se pone una casilla H (head) al principio de la lista
	cuerpo.push_back(Casilla(c, id, x, y)); 	
}

Snake::~Snake() {}

Casilla Snake::Get_Casilla(int i)
{
	return cuerpo[i];
}

int Snake::Get_Partes_Cuerpo()
{
	return cuerpo.size();
}

void Snake::Mover(int i)
{
	/*if(kbhit())
	{
		char tecla = getch();
		
		if(tecla == UP && cuerpo[0].Get_Y() - 1 > 4)
		{
			cuerpo.push_front(Casilla('^', 'H', cuerpo[0].Get_X(), cuerpo[0].Get_Y() - 1));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
		if(tecla == DOWN && cuerpo[0].Get_Y() + 1 < ALTO - 1)
		{
			cuerpo.push_front(Casilla('v', 'H', cuerpo[0].Get_X(), cuerpo[0].Get_Y() + 1));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
		if(tecla == LEFT && cuerpo[0].Get_X() - 1 > 3)
		{
			cuerpo.push_front(Casilla('<', 'H', cuerpo[0].Get_X() - 1, cuerpo[0].Get_Y()));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
		if(tecla == RIGHT && cuerpo[0].Get_X() + 1 < ANCHO - 1)
		{
			cuerpo.push_front(Casilla('>', 'H', cuerpo[0].Get_X() + 1, cuerpo[0].Get_Y()));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
	} // Fin if(kbhit())*/
	switch(i)
	{
	case 80: // ABAJO
	{
		if(cuerpo[0].Get_Y() + 1 < ALTO) 
		{	
			cuerpo.push_front(Casilla('v', 'H', cuerpo[0].Get_X(), cuerpo[0].Get_Y() + 1));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
	}
	break;
	case 72: // ARRIBA
	{
		if(cuerpo[0].Get_Y() - 1 > 0) 
		{
			cuerpo.push_front(Casilla('^', 'H', cuerpo[0].Get_X(), cuerpo[0].Get_Y() - 1));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
	}
	break;
	case 77: // DERECHA
	{
		if(cuerpo[0].Get_X() + 1 < ANCHO) 
		{
			cuerpo.push_front(Casilla('>', 'H', cuerpo[0].Get_X() + 1, cuerpo[0].Get_Y()));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
	}
	break;
	case 75: // IZQUIERDA
	{
		if(cuerpo[0].Get_X() - 1 > 0) 
		{			
			cuerpo.push_front(Casilla('<', 'H', cuerpo[0].Get_X() - 1, cuerpo[0].Get_Y()));
			cuerpo.pop_back();
			// Poner el dibujo de las partes restantes del cuerpo a 254 (cuadradito)
			for(int i = 1; i < cuerpo.size(); i++)
			{
				cuerpo[i].Set_Dibujo(254);
			}
		}
	}
	break;
	} // Fin switch
}

void Snake::Crecer()
{
	char nuevaParte = 254; // 254 = cuadradito
	it = cuerpo.begin();
	if(cuerpo[0].Get_Dibujo() == '^')
		cuerpo.push_back(Casilla(nuevaParte, 'B', cuerpo[cuerpo.size()-1].Get_X(), cuerpo[cuerpo.size()-1].Get_Y() + 1));  
	if(cuerpo[0].Get_Dibujo() == 'v')
		cuerpo.push_back(Casilla(nuevaParte, 'B', cuerpo[cuerpo.size()-1].Get_X(), cuerpo[cuerpo.size()-1].Get_Y() - 1));  
	if(cuerpo[0].Get_Dibujo() == '>')
		cuerpo.push_back(Casilla(nuevaParte, 'B', cuerpo[cuerpo.size()-1].Get_X() - 1, cuerpo[cuerpo.size()-1].Get_Y()));  
	if(cuerpo[0].Get_Dibujo() == '<')
		cuerpo.push_back(Casilla(nuevaParte, 'B', cuerpo[cuerpo.size()-1].Get_X() + 1, cuerpo[cuerpo.size()-1].Get_Y()));  	
}

void Snake::Dibujar()
{
	for(int i = 0; i < cuerpo.size(); i++)
	{
		Funciones::Goto_XY(cuerpo[i].Get_X(), cuerpo[i].Get_Y());
		std::cout << cuerpo[i].Get_Dibujo();
	}
}
