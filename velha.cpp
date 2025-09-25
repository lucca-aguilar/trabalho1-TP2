/**
 * \file  velha.cpp
 */


#include "velha.hpp"

/** 
 * @brief Verifica situação do jogo da velha  
 * @author Lucca Santos Aguilar
 * @param velha descreve a matriz 3x3 que representa o jogo da velha
 * 
 *  @return  1 se o jogador 1 venceu, 2 se o jogador 2 venceu, 0 se empate, -1 se o jogo ainda não terminou e -2 se a situação é inválida.
 */ 

/**
 * \file  velha.cpp
 */

#include "velha.hpp"

int VerificaVelha(int velha[3][3]) {
    int num_x = 0;
    int num_o = 0;
    for (int index_linha = 0; index_linha < 3; index_linha++) {
        for (int index_coluna = 0; index_coluna < 3; index_coluna++) {
            if (velha[index_linha][index_coluna] == 1) {
                num_x++;
            } else if (velha[index_linha][index_coluna] == 2) {
                num_o++;
            }
        }
    }
    int jogadas_totais = num_x + num_o;

    if (num_x > num_o + 1 || num_o > num_x + 1) return -2; 

    int vencedor = VerificaVitoria(velha);
    if (vencedor != 0) {
		if (vencedor == 1 && num_x == num_o) return -2; 
		if (vencedor == 2 && num_x > num_o) return -2; 
		return vencedor; 
	}

    if (jogadas_totais == 9) return 0; 
    
    return -1; 
}


int VerificaVitoria(int velha[3][3]) {
	bool vitoria_o = false;
	bool vitoria_x = false;

	for (int index = 0; index < 3; index++) {
        ChecaTrinca(velha[index][0], velha[index][1], velha[index][2], vitoria_x, vitoria_o); 
        ChecaTrinca(velha[0][index], velha[1][index], velha[2][index], vitoria_x, vitoria_o); 
    }

    ChecaTrinca(velha[0][0], velha[1][1], velha[2][2], vitoria_x, vitoria_o);
    ChecaTrinca(velha[0][2], velha[1][1], velha[2][0], vitoria_x, vitoria_o);

	if (vitoria_x && vitoria_o) {
		return -2;
	} else if (vitoria_x) {
		return 1;
	} else if (vitoria_o) {
		return 2;
	}

    return 0; 
}

void ChecaTrinca(int c1, int c2, int c3, bool& vitoria_x, bool& vitoria_o) {
    if (c1 != 0 && c1 == c2 && c2 == c3) {
        if (c1 == 1) {
            vitoria_x = true;
        } else {
            vitoria_o = true;
        }
    }
}