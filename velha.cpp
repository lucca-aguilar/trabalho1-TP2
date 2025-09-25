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

    if (num_x > num_o + 1 || num_o > num_x + 1) {
        return -2; 
    }

    int vencedor = VerificaVitoria(velha);
    if (vencedor != 0) {
        return vencedor; 
    }

    if (jogadas_totais == 9) {
        return 0; 
    }

    return -1; 
}


int VerificaVitoria(int velha[3][3]) {
	// Checa vitoria em linhas e colunas
    for (int index_linha = 0; index_linha < 3; index_linha++) {
        if (velha[index_linha][0] == velha[index_linha][1] && velha[index_linha][1] == velha[index_linha][2] && velha[index_linha][0] != 0) {
            return velha[index_linha][0];
        }
    }

    for (int index_coluna = 0; index_coluna < 3; index_coluna++) {
        if (velha[0][index_coluna] == velha[1][index_coluna] && velha[1][index_coluna] == velha[2][index_coluna] && velha[0][index_coluna] != 0) {
            return velha[0][index_coluna];
        }
    }

	// Checa vitórias na diagonal principal e na diagonal secundária
    if (velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[0][0] != 0) {
        return velha[0][0];
    } 
	
	if (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0] && velha[0][2] != 0) {
        return velha[0][2];
    }

    return 0; 
}