#pragma once
#include"Queen.h"
#include<vector>

class VecQueen
{
public:
	VecQueen();
	~VecQueen();

	vector<Queen*> VECTOR_QUEEN;

	void ADD(int X,int Y,Bitmap^BMP);
	void DELETE(int X, int Y, Bitmap^BMP);
	void SHOW(Graphics^GR,Bitmap^BMP);
};

VecQueen::VecQueen()
{
}

VecQueen::~VecQueen()
{
}

void VecQueen::ADD(int X, int Y, Bitmap^BMP){
	VECTOR_QUEEN.push_back(new Queen(X, Y, BMP));
}
void VecQueen::SHOW(Graphics^GR, Bitmap^BMP){
	for (int i = 0; i < VECTOR_QUEEN.size(); i++) {
		if (VECTOR_QUEEN[i]->GETTRANSPARENT() == true) {
			VECTOR_QUEEN[i]->DRAW(GR, BMP);
		}
	}
}
void VecQueen::DELETE(int X, int Y,Bitmap^BMP){
	Queen* DELETE = new Queen(X, Y, BMP);
	auto i = find(VECTOR_QUEEN.begin(), VECTOR_QUEEN.end(), DELETE);
	VECTOR_QUEEN.erase(VECTOR_QUEEN.begin() + distance(VECTOR_QUEEN.begin(), i) - 1);
	for (int i = 0; i < VECTOR_QUEEN.size(); i++) {
		if(VECTOR_QUEEN[i]->GETX()==X && VECTOR_QUEEN[i]->GETY() == Y)
		VECTOR_QUEEN[i]->SETTRANSPARENT(false);
	}
}