
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

TEST_CASE("Jogo impossível: 'X' tem duas jogadas a mais que 'O'", "[impossivel]") { 
    int tabuleiro_impossivel[3][3] = { { 1, 2, 1 }, 
                                       { 0, 1, 0 },
                                       { 0, 0, 0 }
                                     };
    REQUIRE( VerificaVelha(tabuleiro_impossivel) == -2 );
}