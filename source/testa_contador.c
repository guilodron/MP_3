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
TEST_CASE("Funcao linhas_comentadas") {
    SECTION("Arquivo sem comentarios"){
        ptr_arq = fopen("arquivo_comum.txt", "r");
        REQUIRE(linhas_comentadas(ptr_arq) == 0);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo sem comentarios")
    SECTION("Arquivo com comentarios"){
        ptr_arq = fopen("arquivo_comentado.txt", "r");
        REQUIRE(linhas_comentadas(ptr_arq) == 5);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo com comentarios")
}  // end TEST_CASE("Funcao linhas_comentadas")
TEST_CASE("Funcao num_linhas"){
    SECTION("Arquivo de codigo"){
    	ptr_arq = fopen("arquivo_comentado.txt", "r");
    	REQUIRE(num_linhas(ptr_arq) == 6);
    	fclose(ptr_arq);
    }  // end SECTION("Arquivo de codigo")
    SECTION("Arquivo vazio"){
        ptr_arq = fopen("arquivo_vazio.txt", "r");
        REQUIRE(num_linhas(ptr_arq) == 0);
        fclose(ptr_arq);
    }  // end SECTION("Arquivo Vazio")
    SECTION("Arquivo com linhas brancas") {
    	ptr_arq = fopen("arquivo_com_linhas_brancas.txt", "r");
    	REQUIRE(num_linhas(ptr_arq) == 0);
    	fclose(ptr_arq);
    }  // end SECTION("Arquivo com linhas brancas")
}  // end TEST_CASE("Funcao num_linhas")

