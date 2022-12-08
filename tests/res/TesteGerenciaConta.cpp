#include "doctest.h"
#include "GerenciaConta.hpp"

TEST_CASE("Teste adicionarCarteira - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteira", 100);
    CHECK(gerente.getContas().size() != 0);
}

TEST_CASE("Teste adicionarConta - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    CHECK(gerente.getContas().size() != 0);
}

TEST_CASE("Teste adicionarConta - Exceção Conta Já Existente") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    CHECK_THROWS_AS(gerente.adicionarConta("conta", 101), ctrexcp::ContaJaExiste);
}

TEST_CASE("Teste removerConta - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    gerente.removerConta("conta");
    CHECK(gerente.getContas().size() == 0);
}

TEST_CASE("Teste adicionarReceita - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    gerente.adicionarReceita("conta", 50, "10/10/2022", "categoria");
    CHECK(gerente.getConta("conta")->getSaldoAtual() == 150);
}

TEST_CASE("Teste adicionarDespesa - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    gerente.adicionarDespesa("conta", 50, "10/10/2022", "categoria");
    CHECK(gerente.getConta("conta")->getSaldoAtual() == 50);
}

TEST_CASE("Teste removerReceita - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    gerente.adicionarReceita("conta", 50, "10/10/2022", "categoria");
    gerente.adicionarReceita("conta", 50, "11/10/2022", "categoria");
    auto it = gerente.getConta("conta")->getTransacoes().rbegin();
    gerente.removerReceita("conta", it->second->getID());
    CHECK(gerente.getConta("conta")->getSaldoAtual() == 150);
}

TEST_CASE("Teste removerDespesa - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 100);
    gerente.adicionarDespesa("conta", 50, "10/10/2022", "categoria");
    gerente.adicionarDespesa("conta", 50, "11/10/2022", "categoria");
    auto it = gerente.getConta("conta")->getTransacoes().rbegin();
    gerente.removerDespesa("conta", it->second->getID());
    CHECK(gerente.getConta("conta")->getSaldoAtual() == 50);
}

TEST_CASE("Teste adicionarTransferencia - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 1000);
    gerente.adicionarConta("conta_2", 1000);
    gerente.adicionarTransferencia(100, "10/10/2022", "categoria", "conta", "conta_2");
    CHECK(gerente.getConta("conta_2")->getSaldoAtual() == 1100);
}

TEST_CASE("Teste removerTransferencia - Caso Base") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta", 1000);
    gerente.adicionarConta("conta_2", 1000);
    gerente.adicionarTransferencia(100, "10/10/2022", "categoria", "conta", "conta_2");
    gerente.adicionarTransferencia(100, "11/10/2022", "categoria", "conta", "conta_2");
    auto it = gerente.getConta("conta")->getTransacoes().rbegin();
    gerente.removerTransferencia("conta", it->second->getID());
    CHECK(gerente.getConta("conta_2")->getSaldoAtual() == 1100);
}
///////////////////
/*     TEST_CASE("Teste adicionarTransacao - Excecao Conta Nao Encontrada (Receita)") {
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteiraA", 500);
    CHECK_THROWS_AS(gerente.adicionarReceita("carteira", 500, "10/11/2022", "categoria"), ctrexcp::ContaNaoEncontrada);
}

TEST_CASE("Teste adicionarTransacao - Excecao Conta Nao Encontrada (Despesa)") {
    Carteira novaCarteira("nome", 1000);
    Despesa novaDespesa(100, "10/11/1999", "despesa", "conta_fantasma");
    std::shared_ptr<Transacao> despesa = std::make_shared<Despesa>(novaDespesa);
    CHECK_THROWS_AS(novaCarteira.adicionarTransacao(despesa), ctrexcp::ContaNaoEncontrada);
} */
 
///////////////

TEST_CASE("Teste PerfilVazio - Caso Base") {
    GerenciaConta gerente;
    CHECK_THROWS_AS(gerente.imprimirContas(), gcexcp::PerfilVazio);
}

TEST_CASE("Teste TipoTransacaoInvalido - Caso Base") {
    GerenciaConta gerente;
    CHECK_THROWS_AS(gerente.listarTransacao("conta1", "emprestimo"), 
                                            trsexcp::TipoTransacaoInvalido);
}

TEST_CASE("Teste CartaoNaoEncontrado - listarDespesasCartao") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta1", 100);
    CHECK_THROWS_AS(gerente.listarDespesasCartao("conta1", "cartao1"),
                                                  cdcexcp::CartaoNaoEncontrado);
}

TEST_CASE("Teste CartaoNaoEncontrado - pagarFaturaCartao") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta1", 100);
    CHECK_THROWS_AS(gerente.pagarFaturaCartao("conta1", "cartao1"),
                                              cdcexcp::CartaoNaoEncontrado);
}

TEST_CASE("Teste CartaoNaoEncontrado - removerCartao") {
    GerenciaConta gerente;
    gerente.adicionarConta("conta1", 100);
    CHECK_THROWS_AS(gerente.removerCartao("conta1", "cartao1"),
                                          cdcexcp::CartaoNaoEncontrado);
}

TEST_CASE("Teste CartaoNaoEncontrado - adicionarCartao") {
    GerenciaConta gerente;
    gerente.adicionarCarteira("conta1", 100);
    CHECK_THROWS_AS(gerente.adicionarCartao("conta1", "cartao1","1234123412341234",
                                            "123", "11", 1000), ctrexcp::ContaNaoPermiteCartao);
}

TEST_CASE("Teste TransacaoNaoEncontrada - removerTransferencia") {
    GerenciaConta gerente;
    gerente.adicionarCarteira("conta1", 100);
    CHECK_THROWS_AS(gerente.removerTransferencia("conta1", 123), trsexcp::TransacaoNaoEncontrada);
}