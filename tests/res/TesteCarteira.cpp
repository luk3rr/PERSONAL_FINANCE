#include "doctest.h"
#include "Carteira.hpp"
#include "Receita.hpp"
#include "Despesa.hpp"
#include "CarteiraExcp.hpp"

TEST_CASE("Teste Construtor Carteira - Exceção Saldo Negativo"){
    CHECK_THROWS_AS(Carteira novaCarteira("nome", -10), ctrexcp::ValorInvalido);
}

TEST_CASE("Teste getSaldoAtual") {
    Carteira novaCarteira("nome", 1);
    
    std::shared_ptr<Receita> deposito1 = 
        std::make_shared<Receita>(novaCarteira.getNome(), 100, "10/11/1999", "categoria");
    std::shared_ptr<Receita> deposito2 = 
        std::make_shared<Receita>(novaCarteira.getNome(), 1000, "10/11/1999", "categoria");

    novaCarteira.adicionarTransacao(deposito1);
    novaCarteira.adicionarTransacao(deposito2);
    CHECK(novaCarteira.getSaldoAtual() == 1101);
}

TEST_CASE("Teste setSaldoAtual - Caso Base") {
    Carteira novaCarteira("nome", 1);
    novaCarteira.setSaldoAtual(100);
    CHECK(novaCarteira.getSaldoAtual() == 100);
}

TEST_CASE("Teste setSaldoAtual - Exceção Saldo Negativo") {
    Carteira novaCarteira("nome", 1);
    CHECK_THROWS_AS(novaCarteira.setSaldoAtual(-10), ctrexcp::ValorInvalido);
}

TEST_CASE("Teste adicionarTransacao - Caso Base Receita") {
    Carteira novaCarteira("nome", 1000);
    Receita novaReceita("nome", 100, "10/11/1999", "receita");
    std::shared_ptr<Transacao> receita = std::make_shared<Receita>(novaReceita);
    novaCarteira.adicionarTransacao(receita);
    CHECK(novaCarteira.getSaldoAtual() == 1100);
}

TEST_CASE("Teste adicionarTransacao - Caso Base Despesa") {
    Carteira novaCarteira("nome", 1000);
    Despesa novaDespesa(100, "10/11/1999", "despesa", "nome");
    std::shared_ptr<Transacao> despesa = std::make_shared<Despesa>(novaDespesa);
    novaCarteira.adicionarTransacao(despesa);
    CHECK(novaCarteira.getSaldoAtual() == 900);
}

TEST_CASE("Teste adicionarTransacao - Excecao Valor Invalido (Receita)") {
    Carteira novaCarteira("nome", 1000);
    Receita novaReceita("nome", -100, "10/11/1999", "receita");
    std::shared_ptr<Transacao> receita = std::make_shared<Receita>(novaReceita);
    CHECK_THROWS_AS(novaCarteira.adicionarTransacao(receita), ctrexcp::ValorInvalido);
}

TEST_CASE("Teste adicionarTransacao - Excecao Saldo Insuficiente (Despesa)") {
    Carteira novaCarteira("nome", 1000);
    Despesa novaDespesa(1100, "10/11/1999", "despesa", "nome");
    std::shared_ptr<Transacao> despesa = std::make_shared<Despesa>(novaDespesa);
    CHECK_THROWS_AS(novaCarteira.adicionarTransacao(despesa), ctrexcp::SaldoInsuficiente);
}

TEST_CASE("Teste removerTransacao - Caso Base (Receita)") {
    Carteira novaCarteira("nome", 1000);
    Receita novaReceita("nome", 100, "10/11/1999", "receita"), novaReceita2("nome", 100, "10/11/1999", "receita");
    std::shared_ptr<Transacao> receita = std::make_shared<Receita>(novaReceita);
    std::shared_ptr<Transacao> receita2 = std::make_shared<Receita>(novaReceita2);
    novaCarteira.adicionarTransacao(receita);
    novaCarteira.adicionarTransacao(receita2);
    novaCarteira.removerTransacao(receita2->getID());
    CHECK(novaCarteira.getSaldoAtual() == 1100);
}

TEST_CASE("Teste removerTransacao - Caso Base (Despesa)") {
    Carteira novaCarteira("nome", 1000);
    Despesa novaDespesa(100, "10/11/1999", "despesa", "nome"), novaDespesa2(100, "10/11/1999", "despesa", "nome");
    std::shared_ptr<Transacao> despesa = std::make_shared<Despesa>(novaDespesa);
    std::shared_ptr<Transacao> despesa2 = std::make_shared<Despesa>(novaDespesa2);
    novaCarteira.adicionarTransacao(despesa);
    novaCarteira.adicionarTransacao(despesa2);
    novaCarteira.removerTransacao(despesa2->getID());
    CHECK(novaCarteira.getSaldoAtual() == 900);
}

