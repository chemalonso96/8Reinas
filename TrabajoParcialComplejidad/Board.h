#pragma once

#include"Dad.h"
using namespace System;
using namespace System::Drawing;

class Board:public Dad
{
public:
	Board();
	~Board();

	void DRAW(Graphics^GR, Bitmap^BMP);

};

Board::Board()
{
	SETY(0);
	SETX(0);
	SETWIDTH(480);
	SETHIGH(480);
}

Board::~Board()
{
}

void Board::DRAW(Graphics^GR, Bitmap^BMP){
	GR->DrawImage(BMP, GETX(), GETY(), GETWIDTH(), GETHIGH());
}
