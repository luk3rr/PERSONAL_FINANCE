#include "CarteiraExcp.hpp"

/*Métodos para ValorInvalido*/
ctrexcp::ValorInvalido::ValorInvalido(double valor, std::string nome) {
    this->_valor = valor;
    this->_nome = nome;
}

ctrexcp::ValorInvalido::ValorInvalido(double valor) {
    this->_valor = valor;
}

std::string  ctrexcp::ValorInvalido::getNome() {
    return this->_nome;
}

double ctrexcp::ValorInvalido::getValor() {
    return this->_valor;
}

const char* ctrexcp::ValorInvalido::what() const throw() {
    return "ERRO 🕵️: Valor Invalido";
}

/*Métodos para ContaNaoEncontrada*/
ctrexcp::ContaNaoEncontrada::ContaNaoEncontrada(std::string nome) {
    this->_nome = nome;
}

std::string ctrexcp::ContaNaoEncontrada::getNome() {
    return this->_nome;
}

const char* ctrexcp::ContaNaoEncontrada::what() const throw() {
    return "ERRO 🕵️: Conta não encontrada";
}


// Metodos para ContaJaExiste

ctrexcp::ContaJaExiste::ContaJaExiste(std::string nome) {
    this->_nome = nome;
}

const char* ctrexcp::ContaJaExiste::what() const throw() {
    return "ERRO 🕵️: Já existem contas cadastradas com esse nome";
}

std::string ctrexcp::ContaJaExiste::getNome() {
    return this->_nome;
}

// Metodos para ContaNaoPermiteCartao

ctrexcp::ContaNaoPermiteCartao::ContaNaoPermiteCartao(std::string nome, std::string subtipo) {
    this->_nome_conta = nome;
    this->_subtipo_conta = subtipo;
}

const char* ctrexcp::ContaNaoPermiteCartao::what() const throw() {
    return "ERRO 🕵️: A conta selecionada nao permite cartao de credito";
}

std::string ctrexcp::ContaNaoPermiteCartao::getNomeConta() {
    return this->_nome_conta;
}

std::string ctrexcp::ContaNaoPermiteCartao::getSubtipoConta() {
    return this->_subtipo_conta;
}

// Metodos para SaldoInsuficiente
ctrexcp::SaldoInsuficiente::SaldoInsuficiente(double saldo, double despesa) {
    this->_saldo = saldo;
    this->_despesa = despesa;
}

const char* ctrexcp::SaldoInsuficiente::what() const throw() {
    return "ERRO 🕵️: Saldo insuficiente para realizar a transação";
}

double ctrexcp::SaldoInsuficiente::getSaldo() {
    return this->_saldo;
}

double ctrexcp::SaldoInsuficiente::getDespesa() {
    return this->_despesa;
}
