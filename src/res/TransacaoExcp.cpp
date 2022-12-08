#include "TransacaoExcp.hpp"

/*Métodos para TransacaoNaoEncontrada*/
trsexcp::TransacaoNaoEncontrada::TransacaoNaoEncontrada(int id) {
    this->_id = id;
}

const char* trsexcp::TransacaoNaoEncontrada::what() const throw() {
    return "ERRO 🕵️: Transação não encontrada";
}

int trsexcp::TransacaoNaoEncontrada::getID() {
    return this->_id;
}

// Metodos para TipoTransacaoInvalido
trsexcp::TipoTransacaoInvalido::TipoTransacaoInvalido(std::string tipo) {
    this->_tipo = tipo;
}

std::string trsexcp::TipoTransacaoInvalido::getTipo() {
    return this->_tipo;
}

const char* trsexcp::TipoTransacaoInvalido::what() const throw() {
    return "ERRO 🕵️: O tipo da transacao é inválida";
}

// Metodos para DataInvalida
trsexcp::DataInvalida::DataInvalida(std::string data) {
    this->_data = data;
}

std::string trsexcp::DataInvalida::getData() {
    return this->_data;
}

const char* trsexcp::DataInvalida::what() const throw() {
    return "ERRO 🕵️: Data informada não está no padrão dd-mm-aaaa ou é inválida";
}

// Metodos TransferenciaInvalida
trsexcp::TransferenciaInvalida::TransferenciaInvalida(std::string nome) {
    this->_nome_da_conta = nome;
}

const char* trsexcp::TransferenciaInvalida::what() const throw() {
    return "ERRO 🕵️: Não é possível realizar uma transferência para uma mesma conta";
}

std::string trsexcp::TransferenciaInvalida::getNomeConta() {
    return this->_nome_da_conta;
}
