#include "doctest.h"
#include "Carteira.hpp"
#include "Despesa.hpp"

TEST_CASE("Teste alterarConta - Caso Base (Despesa)") {
    Carteira novaCarteira("conta_1", 100);
    Carteira novaCarteira_2("conta_2", 100);
    Despesa novaDespesa(10, "11/10/1998", "despesa", "conta_1");
    novaDespesa.alterarConta("conta_2");
    CHECK(novaDespesa.getConta() == "conta_2");
}