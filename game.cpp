#include <iostream>
#include <cstdlib>
#include <vector>

#include "position.h"
#include "position.cpp"

#include "snake.h"
#include "snake.cpp"

#include "bola.h"
#include "bola.cpp"

using  namespace std;

// https://goo.gl/IMBdAn

int linhas = 23, colunas = 64;

int rand_i(){
    srand(time(NULL));

    return (1 + rand()%(linhas - 1));
}

int rand_j(){
    srand(time(NULL));

    return (1 + rand()%(colunas - 1));
}

int main(){
	
	char movimento;
	char A[linhas][colunas];

    snake cobra(linhas/2, colunas/2);

    bola ponto(rand_i(), rand_j());

	for(int i = 0; i < linhas; i++){
    	for(int j = 0; j < colunas; j++){
        	A[i][j] = ' ';
        	if(i == 0 || i == linhas - 1){
            	A[i][j] = '#';
        	}
        	if(j == 0 || j == colunas - 1){
            	A[i][j] = '#';
        	}
    	}
	}

	while(true){

        A[cobra.getcabeca().geti()][cobra.getcabeca().getj()] = cobra.getsimbolo_cabeca();

        for(int c = 0; c < (cobra.gettamanho()-1); ++c){
            int i = cobra.getcorpo(c).geti();
            int j = cobra.getcorpo(c).getj();
            A[i][j] = cobra.getsimbolo_corpo();
        }

    	for(int i = 0; i < linhas; i++){
        	for(int j = 0; j < colunas; j++){
            	cout << A[i][j];
        	}
        	cout << endl;
    	}

        // cobra.print();

    	cin >> movimento;
    	switch(movimento){
        	case 'w':
                cobra.setdirecao(4);
                cobra.andar();
            	break;
        	case 'a':
            	cobra.setdirecao(3);
                cobra.andar();
            	break;
        	case 's':
            	cobra.setdirecao(2);
                cobra.andar();
            	break;
        	case 'd':
            	cobra.setdirecao(1);
                cobra.andar();
            	break;
    	}

    	//Limpatela
       
    	for(int i = 0; i < 70; i++){
        	cout <<"\n";
    	}
    	//Limpatela


	}

	return 0;
}
