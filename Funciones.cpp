#include "Funciones.h"

void Funciones::Goto_XY(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hcon, dwPos);
}

void Funciones::Marco()
{
	char bases = 205;
	char paredes = 186;
	char esquina_sup_dcha = 187; 
	char esquina_inf_dcha = 188;
	char esquina_inf_izq = 200;
	char esquina_sup_izq = 201;
	
	for(int i = 2; i < ANCHO; i++)
	{
		Goto_XY(i,3);
		std::cout << bases;
		Goto_XY(i, ALTO);
		std::cout << bases;
	}
	for(int j = 3; j < ALTO; j++)
	{
		Goto_XY(2, j);
		std::cout << paredes;
		Goto_XY(ANCHO, j);
		std::cout << paredes;
	}
	Goto_XY(2, 3);
	std::cout << esquina_sup_izq;
	Goto_XY(2, ALTO);
	std::cout << esquina_inf_izq;
	Goto_XY(ANCHO, 3);
	std::cout << esquina_sup_dcha;
	Goto_XY(ANCHO, ALTO);
	std::cout << esquina_inf_dcha;
}

void Funciones::No_Cursor()
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 10;
	cci.bVisible = FALSE;
	
	SetConsoleCursorInfo(hcon, &cci);
}
