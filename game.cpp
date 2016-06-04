#include <iostream>
#include <cstdlib>
#include <ctime>
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

    return (1 + rand()%(linhas - 2));
}

int rand_j(){
    srand(time(NULL));

    return (1 + rand()%(colunas - 2));
}

int main(){
	
	char movimento;
	char A[linhas][colunas];

    snake cobra(linhas/2, colunas/2);

    bola ponto(rand_i(), rand_j());

	while(true){

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

        A[ponto.getposicao().geti()][ponto.getposicao().getj()] = ponto.getsimbolo();

        A[cobra.getcabeca().geti()][cobra.getcabeca().getj()] = cobra.getsimbolo_cabeca();

        for(int c = 0; c < cobra.gettamanho(); ++c){
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
            	break;
        	case 'a':
            	cobra.setdirecao(3);
            	break;
        	case 's':
            	cobra.setdirecao(2);
            	break;
        	case 'd':
            	cobra.setdirecao(1);
            	break;
    	}

        cobra.andar();

        for(int c = 0; c < cobra.gettamanho(); ++c){
            if(cobra.getcabeca().equals(cobra.getcorpo(c))){
                return 0;
            }
        }

        for(int i = 0; i < linhas; ++i){
            if(cobra.getcabeca().equals(i, 0)){
                return 0;
            }           
        }

        for(int i = 0; i < linhas; ++i){
            if(cobra.getcabeca().equals(i, colunas-1)){
                return 0;
            }           
        }

        for(int i = 0; i < colunas; ++i){
            if(cobra.getcabeca().equals(0, i)){
                return 0;
            }           
        }

        for(int i = 0; i < colunas; ++i){
            if(cobra.getcabeca().equals(linhas-1, i)){
                return 0;
            }           
        }
        

        if(cobra.getcabeca().equals(ponto.getposicao())){
            ponto.seti(rand_i());
            ponto.setj(rand_j());
        }
        else{
            cobra.cortar();
        }

    	//Limpatela
       
    	for(int i = 0; i < 70; i++){
        	cout <<"\n";
    	}
    	//Limpatela



	}

	return 0;
}
