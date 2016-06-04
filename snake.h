#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "position.h"

using namespace std;

class snake{

private:
	int direcao;
	char simbolo_cabeca;
	char simbolo_corpo;

	position cabeca;
	vector <position> corpo;

public:
	snake(int i, int j);
	~snake();

	void comer();
	void andar();

	bool colisao_corpo();
	bool colisao(position x);
	bool colisao(int i, int j);

	void cortar();

	int gettamanho();
	char getsimbolo_cabeca();
	char getsimbolo_corpo();

	void setdirecao(int d);

	position getcabeca();
	position getcorpo(int index);

	void print();
};

#endif