#include "doctest.h"
#include "CartaoDeCredito.hpp"

// Se houver testes que criem transacoes antes deste o id vai mudar
TEST_CASE("Limite disponível após remover despesa") {
    CartaoDeCredito card1("b1", "12345", "001", "10", 100);
    card1.adicionarDespesa(10, "10/11/1999", "padaria");
    card1.adicionarDespesa(20, "10/11/1999", "padaria");
    card1.removerDespesa(2);
    CHECK(card1.getLimite() - card1.getTotalDespesas() == 90);
}

TEST_CASE("Criar cartão com limite negativo") {
    CHECK_THROWS_AS(CartaoDeCredito card1("c1", "12345", "001", "10", -10), ctrexcp::ValorInvalido);
}

TEST_CASE("Alterar limite") {
    CartaoDeCredito card1("c1", "12345", "001", "12", 1);
    card1.alterarLimiteCartao(1000);
    CHECK(card1.getLimite() == 1000);
}

TEST_CASE("Alterar limite para valor negativo") {
    CartaoDeCredito card1("c1", "12345", "001", "12", 1);
    CHECK_THROWS_AS(card1.alterarLimiteCartao(-1), ctrexcp::ValorInvalido);
}

TEST_CASE("Remover despesa não registrada") {
    CartaoDeCredito card1("c1", "12345", "001", "10", 100);
    CHECK_THROWS_AS(card1.removerDespesa(99), trsexcp::TransacaoNaoEncontrada);
}

TEST_CASE("Somatorio despesas") {
    CartaoDeCredito card1("b1", "12345", "001", "10", 100);
    card1.adicionarDespesa(10, "10/11/1999", "padaria");
    card1.adicionarDespesa(15, "10/11/1999", "padaria");
    card1.adicionarDespesa(1.5, "10/11/1999", "padaria");
    CHECK(card1.getTotalDespesas() == 26.5);
}

TEST_CASE("Adicionar despesa com valor superior ao limite do cartão") {
    CartaoDeCredito card1("b1", "12345", "001", "10", 10);
    CHECK_THROWS_AS(card1.adicionarDespesa(11, "10/11/1999", "padaria"), cdcexcp::LimiteExcedido);
}

TEST_CASE("Adicionar despesa com valor negativo") {
    CartaoDeCredito card1("b1", "12345", "001", "10", 10);
    CHECK_THROWS_AS(card1.adicionarDespesa(-5, "01/12/2001", "padaria"), ctrexcp::ValorInvalido);
}

TEST_CASE("Pegar lista de despesas") {
    CartaoDeCredito card1("b1", "12345", "001", "10", 100);
    card1.adicionarDespesa(13, "10/11/1999", "padaria");
    card1.adicionarDespesa(15, "10/11/1999", "padaria");
    card1.adicionarDespesa(1.512, "10/11/1999", "padaria");
    auto lista = card1.getListaDespesas();
    CHECK(lista.size() == 3);
}
