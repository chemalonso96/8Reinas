#pragma once

#include<vector>

using namespace std;

class VecMatriz
{
private:

	int ESTADO;

public:
	
	int vec_Matriz[8][8];

	VecMatriz();
	~VecMatriz();

	void ADD(int X,int Y,int E);
	void INICIALIZAR();
};

VecMatriz::VecMatriz()
{
	ESTADO = 0;
	INICIALIZAR();
}

VecMatriz::~VecMatriz()
{
}

void VecMatriz::ADD(int X, int Y, int E){
	vec_Matriz[X][Y] = E;//ingresamos datos a este vector 
}

void VecMatriz::INICIALIZAR(){
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8;j++) {
			vec_Matriz[i][j] = 0;
		}
	}
}