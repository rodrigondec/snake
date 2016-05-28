#ifndef BOLA_H
#define BOLA_H

#include "position.h"

class bola{

private:
	char simbolo;
	position posicao;


public:
	bola(int i, int j);
	~bola();

	char getsimbolo();

	position getposicao();
};

#endif