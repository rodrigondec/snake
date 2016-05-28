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


int linhas = 23, colunas = 64, x = linhas/2 , y = colunas/2;

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

    snake cobra(x, y);

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

	A[x][y] = cobra.getsimbolo();

	while(true){

    	for(int i = 0; i < linhas; i++){
        	for(int j = 0; j < colunas; j++){
            	cout << A[i][j];
        	}
        	cout << endl;
    	}

    	cin >> movimento;
    	switch(movimento){
        	case 'w':
            	x--;
            	break;
        	case 'a':
            	y--;
            	break;
        	case 's':
            	x++;
            	break;
        	case 'd':
            	y++;
            	break;
    	}


    	A[x][y] = cobra.getsimbolo();
    	//Limpatela
       
    	for(int i = 0; i < 70; i++){
        	cout <<"\n";
    	}
    	//Limpatela


	}

	return 0;
}
