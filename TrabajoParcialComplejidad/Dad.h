#pragma once

#include<stdio.h>
#include<conio.h>
#include<iostream>

public enum Direction {
	LEFT, RIGTH, UP, DOWN, NOTHING
};

class Dad
{
protected:
	int X, Y, WIDTH, HIGH, DX, DY;
	Direction MOVE;
public:
	Dad();
	~Dad();

	void SETX(int N);
	void SETY(int N);
	void SETWIDTH(int N);
	void SETHIGH(int N);
	void SETDX(int N);
	void SETDY(int N);
	void SETMOVE(Direction N);

	int GETX();
	int GETY();
	int GETWIDTH();
	int GETHIGH();
	int GETDX();
	int GETDY();
	Direction GETMOVE();


};

Dad::Dad()
{
	X = Y = WIDTH = HIGH = DX = DY = NULL;
}

Dad::~Dad()
{
}

void Dad::SETX(int N) { X = N; }
void Dad::SETY(int N) { Y = N; }
void Dad::SETWIDTH(int N) { WIDTH = N; }
void Dad::SETHIGH(int N) { HIGH = N; }
void Dad::SETDX(int N) { DX = N; }
void Dad::SETDY(int N) { DY = N; }
void Dad::SETMOVE(Direction N) { MOVE = N; }

int Dad::GETX() { return X; }
int Dad::GETY() { return Y; }
int Dad::GETWIDTH() { return WIDTH; }
int Dad::GETHIGH() { return HIGH; }
int Dad::GETDX() { return DX; }
int Dad::GETDY() { return DY; }
Direction Dad::GETMOVE() { return MOVE; }