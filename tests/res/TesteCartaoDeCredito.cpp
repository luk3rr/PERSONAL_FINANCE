#include "doctest.h"
#include "CartaoDeCredito.hpp"

// Se forem criadas outras transacoes antes deste teste o ID nao sera igual a 2
TEST_CASE("Remover Despesa") {
    CartaoDeCredito banco1("b1", "1234556781", "001", "10", 100);
    banco1.adicionarDespesa(10, "10/11/1999", "padaria");
    banco1.adicionarDespesa(15, "10/11/1999", "padaria");
    CHECK(banco1.removerDespesa(2) == true);
}

TEST_CASE("Teste Construtor Cartão - Exceção Limite Negativo") {
    CHECK_THROWS_AS(CartaoDeCredito cartao("nome", "101010101010101", 
        "001", "10/11/1999", -10), cdcexcp::LimiteInvalido);
}

TEST_CASE("Teste alterarLimiteCartao - Caso Base") {
    CartaoDeCredito cartao("nome", "101010101010101", "001", "10/11/1999", 1);
    cartao.alterarLimiteCartao(1000);
    CHECK(cartao.getLimite() == 1000);
}

TEST_CASE("Teste alterarLimiteCartao - Exceção Limite negativo") {
    CartaoDeCredito cartao("nome", "101010101010101", "001", "10/11/1999", 1);
    CHECK_THROWS_AS(cartao.alterarLimiteCartao(-100), cdcexcp::LimiteInvalido);
}

TEST_CASE("Soma total do valor das despesas") {
    CartaoDeCredito banco1("b1", "1234556781", "001", "10", 100);
    banco1.adicionarDespesa(10, "10/11/1999", "padaria");
    banco1.adicionarDespesa(15, "10/11/1999", "padaria");
    banco1.adicionarDespesa(1.5, "10/11/1999", "padaria");
    CHECK(banco1.getTotalDespesas() == 26.5);
}

TEST_CASE("Teste adicionarDespesa - Exceção Limite Excedido") {
    CartaoDeCredito banco1("b1", "1234556781", "001", "10", 10);
    CHECK_THROWS_AS(banco1.adicionarDespesa(11, "10/11/1999", "padaria"), cdcexcp::LimiteExcedido);
}