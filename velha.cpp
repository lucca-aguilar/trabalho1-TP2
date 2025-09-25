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

int VerificaVelha(int velha[3][3])
{
	if(!DiferencaNumJogadas(velha))
	{
		return -2;
	}
	return -1;
}

int DiferencaNumJogadas(int velha[3][3])
{
	int num_x = 0;
	int num_o = 0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(velha[i][j] == 1)
			{
				num_x++;
			}
			else if(velha[i][j] == 2)
			{
				num_o++;
			}
		}
	}

	if(num_x > (num_o + 1) || num_o > (num_x + 1))
	{
		return false;
	}

	return true;
}
