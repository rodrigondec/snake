position::position(){}

position::position(int i, int j){
	valor_i = i;
	valor_j = j;
}

position::~position(){}

void position::seti(int i){
	valor_i = i;
}

void position::setj(int j){
	valor_j = j;
}

int position::geti(){
	return valor_i;
}

int position::getj(){
	return valor_j;
}

bool position::equals(position x){
	if(x.geti() == valor_i && x.getj() == valor_j){
		return true;
	}
	return false;
}

bool position::equals(int i, int j){
	if(i == valor_i && j == valor_j){
		return true;
	}
	return false;
}

void position::print(){
	std::cout<<"("<<valor_i<<", "<<valor_j<<")";
}