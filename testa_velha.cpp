
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

TEST_CASE( "Tabuleiro vazio - jogo indefinido", "[indefinido]" ) { 
	int tabuleiro_vazio[3][3]= {   { 0, 0, 0 }, 
	                      { 0, 0, 0 },
						  { 0, 0, 0 }
					  };
    REQUIRE( VerificaVelha(tabuleiro_vazio) == -1 );
} 