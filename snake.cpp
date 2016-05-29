snake::snake(int i, int j){
	direcao = 1;
	simbolo_cabeca = '0';
	simbolo_corpo = 'x';
	tamanho = 3;

	cabeca.seti(i);
	cabeca.setj(j);

	position parte2(i, (j-1));
	corpo.push_back(parte2);

	position parte3(i, (j-2));
	corpo.push_back(parte3);
}

snake::~snake(){}

void snake::comer(){
	tamanho++;
}

void snake::andar(){

	int i = cabeca.geti();
	int j = cabeca.getj();

	vector<position>::iterator it = corpo.begin();

	switch(direcao){
    	case 1:
        	j++;

        	corpo.insert(it, cabeca);

        	cabeca.setj(j);

        	break;
    	case 2:
        	i++;

        	corpo.insert(it, cabeca);

        	cabeca.seti(i);

        	break;
    	case 3:
        	j--;

        	corpo.insert(it, cabeca);

        	cabeca.setj(j);

        	break;
    	case 4:
        	i--;

        	corpo.insert(it, cabeca);

        	cabeca.seti(i);

        	break;
	}
}

bool snake::colisao_corpo(){
	for(int i = 0; i < corpo.size(); ++i){
		return cabeca.equals(corpo[i]);
	}
}

bool snake::colisao(position x){
	return cabeca.equals(x);
}

bool snake::colisao(int i, int j){
	return cabeca.equals(i, j);
}

void snake::cortar(){
	corpo.pop_back();
}

int snake::gettamanho(){
	return tamanho;
}

char snake::getsimbolo_cabeca(){
	return simbolo_cabeca;
}

char snake::getsimbolo_corpo(){
	return simbolo_corpo;
}

position snake::getcabeca(){
	return cabeca;
}

position snake::getcorpo(int index){
	return corpo[index];
}

void snake::setdirecao(int d){
	direcao = d;
}

void snake::print(){
	std::cout<<"Cabeça: ";
	cabeca.print();
	std::cout<<std::endl;
	for (int i = 0; i < corpo.size(); ++i){
		std::cout<<"Corpo "<<i<<": ";
		corpo[i].print();
		std::cout<<std::endl;
	}
}