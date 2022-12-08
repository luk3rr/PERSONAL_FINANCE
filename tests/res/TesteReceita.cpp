#include "doctest.h"
#include "Carteira.hpp"
#include "Receita.hpp"

TEST_CASE("Teste alterarConta - Caso Base (Receita)") {
    Carteira novaCarteira("conta_1", 100);
    Carteira novaCarteira_2("conta_2", 100);
    Receita novaReceita("conta_1", 10, "11/10/1998", "receita");
    novaReceita.alterarConta("conta_2");
    CHECK(novaReceita.getConta() == "conta_2");
}
