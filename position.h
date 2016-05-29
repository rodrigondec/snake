#ifndef POSITION_H
#define POSITION_H

class position{

private:
	int valor_i;
	int valor_j;

public:
	position();
	position(int i, int j);
	~position();
	
	void seti(int i);
	void setj(int j);

	int geti();
	int getj();

	bool equals(position x);
	bool equals(int i, int j);

	void print();
};

#endif