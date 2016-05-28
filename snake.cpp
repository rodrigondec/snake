snake::snake(int i, int j){
	simbolo = '0';
	tamanho = 1;
	posicao.seti(i);
	posicao.setj(j);
}

snake::~snake(){}

void snake::comer(){
	tamanho++;
}

int snake::gettamanho(){
	return tamanho;
}

char snake::getsimbolo(){
	return simbolo;
}

position snake::getposicao(){
	return posicao;
}