#ifndef SNAKE_H
#define SNAKE_H

#include "position.h"

using namespace std;

class snake{

private:
	int tamanho;
	char simbolo;
	position posicao;

	vector <position> corpo;

public:
	snake(int i, int j);
	~snake();
	void comer();

	int gettamanho();
	char getsimbolo();

	position getposicao();
};

#endif