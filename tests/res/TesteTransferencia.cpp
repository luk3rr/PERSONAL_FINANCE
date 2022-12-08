#include "doctest.h"
#include "Carteira.hpp"
#include "Transferencia.hpp"
#include "TransacaoExcp.hpp"
#include "CarteiraExcp.hpp"
#include "GerenciaConta.hpp"

TEST_CASE("Teste alterarDestino - Caso Base"){
    Carteira novaCarteiraA("carteiraA", 1000), novaCarteiraB("carteiraB", 1000), novaCarteiraC("carteiraC", 1000);
    Transferencia novaTransferencia(100, "11/11/2022", "categoria", "carteiraA", "carteiraB");
    novaTransferencia.alterarDestino("carteiraC");
    CHECK(novaTransferencia.getDestino() == "carteiraC");
}

TEST_CASE("Teste alterarOrigem - Caso Base"){
    Transferencia novaTransferencia(100, "11/11/2022", "categoria", "origem", "destino");
    novaTransferencia.alterarOrigem("nova_origem");
    CHECK(novaTransferencia.getOrigem() == "nova_origem");
}

TEST_CASE("Teste Construtor de Transferência - Exceção Destino Invalido"){
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteiraA", 1000);
    gerente.adicionarCarteira("carteiraB", 1000);
    
    CHECK_THROWS_AS(gerente.adicionarTransferencia(100, "11/11/2022", "categoria", "carteiraA", "carteiraC"),
        ctrexcp::ContaNaoEncontrada);
}

TEST_CASE("Teste Construtor de Transferência - Exceção Origem Invalida"){
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteiraA", 1000);
    gerente.adicionarCarteira("carteiraB", 1000);

    CHECK_THROWS_AS(gerente.adicionarTransferencia(100, "11/11/2022", "categoria", "carteiraC", "carteiraA"),
        ctrexcp::ContaNaoEncontrada);
}

TEST_CASE("Teste Construtor de Transferência - Exceção Saldo Insuficiente"){
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteiraA", 100);
    gerente.adicionarCarteira("carteiraB", 100);
    CHECK_THROWS_AS(gerente.adicionarTransferencia(2000, "11/11/2022", "categoria", "carteiraA", "carteiraB"),
        ctrexcp::ValorInvalido);
}

TEST_CASE("Teste Construtor de Transferência - Exceção Valor Invalido"){
    GerenciaConta gerente;
    gerente.adicionarCarteira("carteiraA", 100);
    gerente.adicionarCarteira("carteiraB", 100);
    CHECK_THROWS_AS(gerente.adicionarTransferencia(-100, "11/11/2022", "categoria", "carteiraA", "carteiraB"),
        ctrexcp::ValorInvalido);
}

