#pragma once

#include"Dad.h"
using namespace std;
using namespace System::Drawing;

class Queen :public Dad
{
private:
	bool TRANSPARENT;
	int WIDTH_I;
	int HIGH_I;
	int POINT_H;
	int POINT_V;
public:
	Queen(int X,int Y,Bitmap^BMP);
	~Queen();
	Queen();

	void DRAW(Graphics^GR, Bitmap^BMP);
	void SETTRANSPARENT(bool N);
	bool GETTRANSPARENT();
};

Queen::Queen(int X, int Y, Bitmap^BMP)
{
	WIDTH_I = BMP->Width;
	HIGH_I = BMP->Height;
	SETX(X);
	SETY(Y);
	SETWIDTH(60);
	SETHIGH(60);
	SETTRANSPARENT(true);
}

Queen::~Queen()
{
}

Queen::Queen()
{
}

void Queen::DRAW(Graphics^GR, Bitmap^BMP){
	GR->DrawImage(BMP, GETX(),GETY(),GETWIDTH(),GETHIGH());
}

void Queen::SETTRANSPARENT(bool N){
	TRANSPARENT = N;
}
bool Queen::GETTRANSPARENT(){
	return TRANSPARENT;
}