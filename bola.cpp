bola::bola(int i, int j){
	simbolo = '*';
	posicao.seti(i);
	posicao.setj(j);
}

bola::~bola(){}

char bola::getsimbolo(){
	return simbolo;
}

void bola::seti(int i){
	posicao.seti(i);
}

void bola::setj(int j){
	posicao.setj(j);
}

position bola::getposicao(){
	return posicao;
}