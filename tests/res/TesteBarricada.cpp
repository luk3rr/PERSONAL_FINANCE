#include "doctest.h"
#include "Barricada.hpp"

TEST_CASE("Barricada - Cartão válido - Caso Base") {
    CHECK(Barricada::validar_cartao("1234123412341234", "123", "12"));
}

TEST_CASE("Barricada - NumeroInvalido") {
    CHECK_THROWS_AS(Barricada::validar_cartao("1234", "123", "12"), cdcexcp::NumeroInvalido);
}

TEST_CASE("Barricada - CVVInvalido") {
    CHECK_THROWS_AS(Barricada::validar_cartao("1234123412341234", "1", "12"), cdcexcp::CVVInvalido);
}

TEST_CASE("Barricada - FechamentoInvalido") {
    CHECK_THROWS_AS(Barricada::validar_cartao("1234123412341234", "123", "50"), cdcexcp::FechamentoInvalido);
}

TEST_CASE("Barricada - Transferência válida - Caso Base") {
    CHECK(Barricada::validar_transferencia("12/12/2012", "conta1", "conta2"));
}

TEST_CASE("Barricada - Data inválida transferência") {
    CHECK_THROWS_AS(Barricada::validar_transferencia("32/10/2010", "conta1", "conta2"), trsexcp::DataInvalida);
}

TEST_CASE("Barricada - Transferência pra mesma conta") {
    CHECK_THROWS_AS(Barricada::validar_transferencia("10/10/2010", "conta1", "conta1"), trsexcp::TransferenciaInvalida);
}

TEST_CASE("Exceção Data Invalida - Caso Base"){
    CHECK(Barricada::validar_data("31/12/2022"));
}

TEST_CASE("Exceção Data Invalida - Dia maior que 31"){
    CHECK_THROWS_AS(Barricada::validar_data("32/12/2022"), trsexcp::DataInvalida);
}