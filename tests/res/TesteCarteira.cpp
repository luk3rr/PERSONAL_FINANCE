#include "Receita.hpp"
#include "TransacaoExcp.hpp"
#include "doctest.h"
#include "Carteira.hpp"

// Variaveis do tipo receita com o nome "aux_id" sao usadas para saber qual o ID das ultimas
// transacoes

TEST_CASE("Pegar uma transacao") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    wallet.adicionarDespesa(120, "10/10/2010", "c1");
    auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    CHECK(wallet.getTransacao(ultimo_id - 2)->getValor() == 30);
}

TEST_CASE("Criar carteira com saldo inicial negativo") {
    CHECK_THROWS_AS(Carteira("w1", -1), ctrexcp::ValorInvalido);
}

TEST_CASE("Adicionar receita com valor negativo") {
    Carteira wallet = Carteira("w1", 100);
    CHECK_THROWS_AS(wallet.adicionarReceita(-230, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Remover uma receita que não existe") {
    Carteira wallet = Carteira("w1", 100);
    CHECK_THROWS_AS(wallet.removerReceita(100), trsexcp::TransacaoNaoEncontrada);
}

TEST_CASE("Adicionar despesa com valor negativo") {
    Carteira wallet = Carteira("w1", 100);
    CHECK_THROWS_AS(wallet.adicionarDespesa(-230, "10/10/2010", "c1"), ctrexcp::ValorInvalido);
}

TEST_CASE("Remover uma despesa que não existe") {
    Carteira wallet = Carteira("w1", 100);
    CHECK_THROWS_AS(wallet.removerDespesa(100), trsexcp::TransacaoNaoEncontrada);
}

TEST_CASE("Pegar map de transacoes") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    wallet.adicionarDespesa(120, "10/10/2010", "c1");
    CHECK(wallet.getTransacoes().size() == 3);
}

TEST_CASE("Pegar map de transacoes") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    wallet.adicionarDespesa(120, "10/10/2010", "c1");
    CHECK(wallet.getTransacoes().size() == 3);
}

TEST_CASE("Verificar remoção de receita/despesa") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    wallet.adicionarDespesa(50, "10/10/2010", "c1");
    wallet.adicionarDespesa(10, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    wallet.removerDespesa(ultimo_id - 2);
    wallet.removerReceita(ultimo_id - 4);
    CHECK(wallet.getTransacoes().size() == 3);
}

TEST_CASE("Pegar uma transacao") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    wallet.adicionarReceita(30, "10/10/2010", "c1");
    wallet.adicionarDespesa(120, "10/10/2010", "c1");
    CHECK_THROWS_AS(wallet.getTransacao(100), trsexcp::TransacaoNaoEncontrada);
}

TEST_CASE("Verificar saldo apos adicionar uma receita") {
     Carteira wallet = Carteira("w1", 100);
     wallet.adicionarReceita(20, "10/10/2010", "c1");
     CHECK(wallet.getSaldoAtual() == 120);
}

TEST_CASE("Verificar saldo apos remover uma receita") {
     Carteira wallet = Carteira("w1", 100);
     wallet.adicionarReceita(20, "10/10/2010", "c1");
     auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
     int ultimo_id = aux_id.getID();
     wallet.removerReceita(ultimo_id - 1);
     CHECK(wallet.getSaldoAtual() == 100);
}

TEST_CASE("Verificar saldo apos adicionar uma despesa") {
     Carteira wallet = Carteira("w1", 100);
     wallet.adicionarDespesa(20, "10/10/2010", "c1");
     CHECK(wallet.getSaldoAtual() == 80);
}

TEST_CASE("Verificar saldo apos remover uma despesa") {
     Carteira wallet = Carteira("w1", 100);
     wallet.adicionarDespesa(20, "10/10/2010", "c1");
     auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
     int ultimo_id = aux_id.getID();
     wallet.removerDespesa(ultimo_id - 1);
     CHECK(wallet.getSaldoAtual() == 100);
}

TEST_CASE("Remover receita usando o metodo de remover despesa") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarReceita(20, "10/10/2010", "c1");
    auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    CHECK_THROWS_AS(wallet.removerDespesa(ultimo_id - 1), trsexcp::TipoTransacaoInvalido);
}

TEST_CASE("Remover despesa usando o metodo de remover receita") {
    Carteira wallet = Carteira("w1", 100);
    wallet.adicionarDespesa(20, "10/10/2010", "c1");
    auto aux_id = Receita("w1", 1, "10/10/2010", "c1");
    int ultimo_id = aux_id.getID();
    CHECK_THROWS_AS(wallet.removerReceita(ultimo_id - 1), trsexcp::TipoTransacaoInvalido);
}
