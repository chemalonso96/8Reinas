#pragma once

#include"VecQueen.h"
#include"VecQueenEnemigo.h"
#include"Board.h"
#include"VecMatriz.h"
struct MACHINE {
	int X;
	int Y;
};

class Principal
{
public:

	VecQueen* OBJ_VEC_QUEEN;//HUMAN
	VecQueenEnemigo* OBJ_VEC_QUEEN_ENEMIGO;
	Board* OBJ_BOARD;
	VecMatriz* OBJ_VEC_MATRIZ;
	vector<int> ARRAUX[8];
public:
	int ScoreComputer;
	int ScorePlayer;
	int Puesto;
	int BEST;

	Principal();
	~Principal();

	void SHOWALL(Graphics^GR, Bitmap^BMPQUEEN_1,Bitmap^BMPBOARD);
	void MOVEHUMANO(int x, int y, Bitmap^BMP);
	void LLENADO_DE_1(int x,int y);
	void LLENADO_DE_0(int x, int y);
	void ELMEJORMOVIMIENTO(Bitmap^BMP);
	void ELIMINAR_MIO(int x, int y, Bitmap^BMP);
	void ELIMINAR_OTRO(int x, int y, Bitmap^BMP);
	int VALIDARGANADOR();
};

Principal::Principal()
{
	OBJ_VEC_QUEEN = new VecQueen();
	OBJ_VEC_QUEEN_ENEMIGO = new VecQueenEnemigo();
	OBJ_BOARD = new Board(); 
	OBJ_VEC_MATRIZ = new VecMatriz();
	ScoreComputer = 0;
	ScorePlayer = 0;
	Puesto = 3;//para el humano
	BEST = 0;
}

Principal::~Principal()
{
}

void Principal::SHOWALL(Graphics^GR, Bitmap^BMPQUEEN_1, Bitmap^BMPBOARD) {
	OBJ_BOARD->DRAW(GR, BMPBOARD);
	OBJ_VEC_QUEEN->SHOW(GR, BMPQUEEN_1);
	OBJ_VEC_QUEEN_ENEMIGO->SHOW(GR, BMPQUEEN_1);
}

void Principal::MOVEHUMANO(int x,int y,Bitmap^BMP){
	if (OBJ_VEC_MATRIZ->vec_Matriz[x / 60][y / 60] == 2) {
		return;
	}
	if (OBJ_VEC_MATRIZ->vec_Matriz[x / 60][y / 60] == 1 ||
		OBJ_VEC_MATRIZ->vec_Matriz[x / 60][y / 60] == 3) {
		ScorePlayer = ScorePlayer - 5;
		return;
	}

	//Message("EL GANADOR ES: "+ VALIDARGANADOR());
	OBJ_VEC_QUEEN->ADD(x, y, BMP);
	ScorePlayer = ScorePlayer + 10;
	OBJ_VEC_MATRIZ->ADD(x / 60, y / 60, Puesto);
	LLENADO_DE_1(x / 60, y / 60);
	ELMEJORMOVIMIENTO(BMP);
}


void Principal::LLENADO_DE_1(int x,int y)
{
	int p1, P1;
	int p2, P2;
	int p3, P3;
	int p4, P4;
	p1 = x;	P1 = y;
	p2 = x;	P2 = y;
	p3 = x;	P3 = y;
	p4 = x;	P4 = y;
	if (OBJ_VEC_MATRIZ->vec_Matriz[x][y] == 3 || OBJ_VEC_MATRIZ->vec_Matriz[x][y] == 2) {
		//LLENADO DE HORIZONTALES Y VERTICALES
		for (int i = x + 1; i < 8; i++) {
			OBJ_VEC_MATRIZ->ADD(i, y, 1);
		}
		for (int j = y + 1; j < 8; j++) {
			OBJ_VEC_MATRIZ->ADD(x, j, 1);
		}
		for (int k = x - 1; k >= 0; k--) {
			OBJ_VEC_MATRIZ->ADD(k, y, 1);
		}
		for (int l = y - 1; l >= 0; l--) {
			OBJ_VEC_MATRIZ->ADD(x, l, 1);
		}
		//LLENADO DE DIAGONALES
		for (int i = x + 1; i < 8; i++) {//DIAGONAL CUARTO OCTETO 
			p1++;//suma x
			P1++;//suma y
			OBJ_VEC_MATRIZ->ADD(p1,P1, 1);
		}
		for (int j = y - 1; j >= 0; j--) {//DIAGONAL SEGUNDO OCTETO
			p2--;//resta x
			P2--;//resta y
			OBJ_VEC_MATRIZ->ADD(p2, P2, 1);
		}
		for (int k = y - 1; k >= 0; k--) {
			p3++;//suma x
			P3--;//resta y
			OBJ_VEC_MATRIZ->ADD(p3, P3, 1);
		}
		for (int l = x - 1; l >= 0; l--) {
			p4--;//resta x
			P4++;//suma y
			OBJ_VEC_MATRIZ->ADD(p4, P4, 1);
		}
	}
}
void Principal::LLENADO_DE_0(int x, int y) {
	int p1, P1;
	int p2, P2;
	int p3, P3;
	int p4, P4;
	p1 = x;	P1 = y;
	p2 = x;	P2 = y;
	p3 = x;	P3 = y;
	p4 = x;	P4 = y;
	if (OBJ_VEC_MATRIZ->vec_Matriz[x][y] == 0) {
		//LLENADO DE HORIZONTALES Y VERTICALES
		for (int i = x + 1; i < 8; i++) {
			OBJ_VEC_MATRIZ->ADD(i, y, 0);
		}
		for (int j = y + 1; j < 8; j++) {
			OBJ_VEC_MATRIZ->ADD(x, j, 0);
		}
		for (int k = x - 1; k >= 0; k--) {
			OBJ_VEC_MATRIZ->ADD(k, y, 0);
		}
		for (int l = y - 1; l >= 0; l--) {
			OBJ_VEC_MATRIZ->ADD(x, l, 0);
		}
		//LLENADO DE DIAGONALES
		for (int i = x + 1; i < 8; i++) {
			p1++;//suma x
			P1++;//suma y
			OBJ_VEC_MATRIZ->ADD(p1, P1, 0);
		}
		for (int j = y - 1; j >= 0; j--) {
			p2--;//resta x
			P2--;//resta y
			OBJ_VEC_MATRIZ->ADD(p2, P2, 0);
		}
		for (int k = y - 1; k >= 0; k--) {
			p3++;//suma x
			P3--;//resta y
			OBJ_VEC_MATRIZ->ADD(p3, P3, 0);
		}
		for (int l = x - 1; l >= 0; l--) {
			p4--;//resta x
			P4++;//suma y
			OBJ_VEC_MATRIZ->ADD(p4, P4, 0);
		}
	}
}

void Principal::ELMEJORMOVIMIENTO(Bitmap^BMP) {
	int a, b, c;
	int m, n;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				c = j;
				if (OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 0) {
					OBJ_VEC_MATRIZ->ADD(i, j, 2);//el dos es para la maquina 
					ScoreComputer = ScoreComputer + 10;
					a = i;
					b = j;
					break;
				}
			}
			if (OBJ_VEC_MATRIZ->vec_Matriz[i][c] == 1 || OBJ_VEC_MATRIZ->vec_Matriz[i][c] == 3) {
				continue;
			}
			else if (OBJ_VEC_MATRIZ->vec_Matriz[i][c] == 2) {
				break;
			}
		}
	

	/*********/
	LLENADO_DE_1(a, b);
	a = a * 60;
	b = b * 60;
	OBJ_VEC_QUEEN_ENEMIGO->ADD(a , b , BMP);
}

void Principal::ELIMINAR_MIO(int x, int y, Bitmap^BMP) {
	ScorePlayer = ScorePlayer - 10;
	OBJ_VEC_QUEEN->DELETE(x, y, BMP);
	OBJ_VEC_MATRIZ->vec_Matriz[x / 60][y / 60] = 0;
	LLENADO_DE_0(x / 60, y / 60);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 2 || 
				OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 3) {
				LLENADO_DE_1(i, j);
			}
		}
	}
}

void Principal::ELIMINAR_OTRO(int x, int y, Bitmap^BMP) {
	ScoreComputer = ScoreComputer - 10;
	OBJ_VEC_QUEEN_ENEMIGO->DELETE(x, y, BMP);
	OBJ_VEC_MATRIZ->vec_Matriz[x / 60][y / 60] = 0;
	LLENADO_DE_0(x / 60, y / 60);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 2 ||
				OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 3) {
				LLENADO_DE_1(i, j);
			}
		}
	}
}

int Principal::VALIDARGANADOR(){
	int dato = 0;
	int a, b;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 1 ||
				OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 2 || 
				OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 3) {
				a = i;
				b = j;
				continue;
			}
			else if(OBJ_VEC_MATRIZ->vec_Matriz[i][j] == 0) {
				break;
			}
		}
		break;
	}
	if (a == 7 && b == 7) {
		BEST = (ScoreComputer < ScorePlayer) ? ScorePlayer : ScoreComputer;
		if (BEST == ScoreComputer) {
			dato = 1;
		}
		else {
			dato = -1;
		}
	}
	return dato;
}