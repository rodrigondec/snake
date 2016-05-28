bola::bola(int i, int j){
	simbolo = '*';
	posicao.seti(i);
	posicao.setj(j);
}

bola::~bola(){}

char bola::getsimbolo(){
	return simbolo;
}

position bola::getposicao(){
	return posicao;
}