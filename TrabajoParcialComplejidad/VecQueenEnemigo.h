#pragma once

#include"Queen.h"
#include<vector>

class VecQueenEnemigo
{
public:
	VecQueenEnemigo();
	~VecQueenEnemigo();

	vector<Queen*> VECTOR_QUEEN_ENEMIGO;

	void ADD(int X, int Y, Bitmap^BMP);
	void DELETE(int X, int Y, Bitmap^BMP);
	void SHOW(Graphics^GR, Bitmap^BMP);
};

VecQueenEnemigo::VecQueenEnemigo()
{
}

VecQueenEnemigo::~VecQueenEnemigo()
{
}

void VecQueenEnemigo::ADD(int X, int Y, Bitmap^BMP) {
	VECTOR_QUEEN_ENEMIGO.push_back(new Queen(X, Y, BMP));
}
void VecQueenEnemigo::SHOW(Graphics^GR, Bitmap^BMP) {
	for (int i = 0; i < VECTOR_QUEEN_ENEMIGO.size(); i++) {
		if (VECTOR_QUEEN_ENEMIGO[i]->GETTRANSPARENT() == true) {
			VECTOR_QUEEN_ENEMIGO[i]->DRAW(GR, BMP);
		}
	}
}
void VecQueenEnemigo::DELETE(int X, int Y, Bitmap^BMP) {
	Queen* DELETE = new Queen(X, Y, BMP);
	auto i = find(VECTOR_QUEEN_ENEMIGO.begin(), VECTOR_QUEEN_ENEMIGO.end(), DELETE);
	VECTOR_QUEEN_ENEMIGO.erase(VECTOR_QUEEN_ENEMIGO.begin() + distance(VECTOR_QUEEN_ENEMIGO.begin(), i) - 1);
	for (int i = 0; i < VECTOR_QUEEN_ENEMIGO.size(); i++) {
		if (VECTOR_QUEEN_ENEMIGO[i]->GETX() == X && VECTOR_QUEEN_ENEMIGO[i]->GETY() == Y)
			VECTOR_QUEEN_ENEMIGO[i]->SETTRANSPARENT(false);
	}
}