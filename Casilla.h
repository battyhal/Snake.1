#ifndef CASILLA_H
#define CASILLA_H

class Casilla {

	private:
		char dibujo;
		char ID;
		int x;
		int y;

	protected:
	
	public:
		Casilla();
		Casilla(char c, char id, int i, int j);
		~Casilla();
		
		char Get_Dibujo();
		char Get_ID();
		int  Get_X();
		int  Get_Y();
		void Set_Dibujo(char c);
		void Set_ID(char c);
		void Set_X(int i);
		void Set_Y(int j);
};

#endif

