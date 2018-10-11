#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "contador.hpp"

FILE* ptr_arq;
TEST_CASE("Funcao total_linhas"){
    SECTION("Arquivo Vazio"){
        ptr_arq = fopen("arquivo_vazio.txt", "r");
        REQUIRE(total_linhas(ptr_arq) == 0);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo Vazio")
    SECTION("Arquivo com linhas brancas") {
    	ptr_arq = fopen("arquivo_com_linhas_brancas.txt", "r");
    	REQUIRE(total_linhas(ptr_arq) == 10);
    	fclose(ptr_arq);
    }  // end SECTION("Arquivo com linhas brancas")
    SECTION("Arquivo comum") {
        ptr_arq = fopen("arquivo_comum.txt", "r");
        REQUIRE(total_linhas(ptr_arq) == 10);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo comum")
} // end TEST_CASE("Funcao total_linhas")
TEST_CASE("Funcao linhas_em_branco") {
    SECTION("Arquivo Vazio") {
        ptr_arq = fopen("arquivo_vazio.txt", "r");
        REQUIRE(linhas_em_branco(ptr_arq) == 0);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo Vazio")
    SECTION("Arquivo com linhas brancas") {
    	ptr_arq = fopen("arquivo_com_linhas_brancas.txt", "r");
    	REQUIRE(linhas_em_branco(ptr_arq) == 10);
    	fclose(ptr_arq);
    }  // end SECTION("Arquivo com linhas brancas")
    SECTION("Arquivo comum") {
        ptr_arq = fopen("arquivo_comum.txt", "r");
        REQUIRE(linhas_em_branco(ptr_arq) == 4);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo comum")
}  // end TEST_CASE("Funcao linhas_em_branco")
