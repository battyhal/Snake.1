#include "Casilla.h"

Casilla::Casilla() 
{
	dibujo = ' ';
	ID = ' ';	
	x = 0;
	y = 0;
}

Casilla::Casilla(char c, char id, int i, int j)
{
	dibujo = c;
	ID = id; // ID puede ser H (head) o B (body)
	x = i;
	y = j;
}

Casilla::~Casilla() {}

char Casilla::Get_Dibujo() { return dibujo; }
char Casilla::Get_ID(){	return ID; }
int  Casilla::Get_X() { return x; }
int  Casilla::Get_Y() { return y; }
void Casilla::Set_Dibujo(char c) { dibujo = c; }
void Casilla::Set_ID(char c) { ID = c; }
void Casilla::Set_X(int i) { x += i; }
void Casilla::Set_Y(int j) { y += j; }


