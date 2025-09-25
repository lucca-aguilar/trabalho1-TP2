
/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"

TEST_CASE( "Tabuleiro vazio - jogo indefinido", "[indefinido]" ) { 
	int tabuleiro_vazio[3][3]= { { 0, 0, 0 }, 
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

TEST_CASE("Jogo impossível: 'O' tem duas jogadas a mais que 'X'", "[impossivel]") { 
    int tabuleiro_impossivel[3][3] = { { 2, 1, 2 }, 
                                       { 0, 0, 0 },
                                       { 0, 2, 0 }
                                     };
    REQUIRE( VerificaVelha(tabuleiro_impossivel) == -2 );
}

TEST_CASE( "Vitória do O na primeira coluna", "[vitoria_O]" ) { 
    int vitoria_o_coluna_1[3][3]= { { 2, 1, 1 }, 
                                    { 2, 0, 0 },
                                    { 2, 0, 0 }
                                  };
    REQUIRE( VerificaVelha(vitoria_o_coluna_1) == 2 );
}

TEST_CASE( "Vitória do X na primeira coluna", "[vitoria_X]" ) { 
    int vitoria_X_coluna_1[3][3]= { { 1, 2, 0 }, 
                                    { 1, 0, 0 },
                                    { 1, 0, 2 }
                                  };
    REQUIRE( VerificaVelha(vitoria_X_coluna_1) == 1 );
}

TEST_CASE( "Vitória do O na segunda coluna", "[vitoria_O]" ) { 
    int vitoria_o_coluna_2[3][3]= { { 1, 2, 1 }, 
                                    { 0, 2, 0 },
                                    { 0, 2, 0 }
                                  };
    REQUIRE( VerificaVelha(vitoria_o_coluna_2) == 2 );
}

TEST_CASE( "Vitória do X na terceira coluna", "[vitoria_X]" ) { 
    int vitoria_X_coluna_3[3][3]= { { 0, 2, 1 }, 
                                    { 0, 2, 1 },
                                    { 0, 0, 1 }
                                  };
    REQUIRE( VerificaVelha(vitoria_X_coluna_3) == 1 );
}

TEST_CASE( "Vitória do O na primeira linha", "[vitoria_O]" ) { 
    int vitoria_o_linha_1[3][3]= { { 2, 2, 2 }, 
                                   { 1, 0, 0 },
                                   { 1, 0, 0 }
                                };
    REQUIRE( VerificaVelha(vitoria_o_linha_1) == 2 );
}

TEST_CASE("Vitória de X na diagonal principal", "[vitoria_x]") {
    int vitoria_x_diagonal_principal[3][3] = { {1, 2, 0},
                            {0, 1, 2},
                            {0, 0, 1} };
    REQUIRE(VerificaVelha(vitoria_x_diagonal_principal) == 1);
}