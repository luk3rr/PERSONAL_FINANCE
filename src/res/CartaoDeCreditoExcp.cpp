#include "CartaoDeCreditoExcp.hpp"

/*Métodos LimiteExcedido*/

cdcexcp::LimiteExcedido::LimiteExcedido(std::string nome_cartao,
                                        std::string numero_cartao,
                                        double limite_cartao,
                                        double soma_despesas_atuais) {
    this->_nome_cartao = nome_cartao;
    this->_numero_cartao = numero_cartao;
    this->_limite_cartao = limite_cartao;
    this->_soma_despesas_atuais = soma_despesas_atuais;
}

const char* cdcexcp::LimiteExcedido::what() const throw() {
    return "ERRO 🕵️: Limite do cartao excedido";
}

std::string cdcexcp::LimiteExcedido::getNomeCartao() {
    return this->_nome_cartao;
}

std::string cdcexcp::LimiteExcedido::getNumeroCartao() {
    return this->_numero_cartao;
}

double cdcexcp::LimiteExcedido::getLimiteCartao() {
    return this->_limite_cartao;
}

/*Métodos Exceção LimiteInvalido*/

cdcexcp::LimiteInvalido::LimiteInvalido(std::string nome_cartao,
                                        std::string numero_cartao,
                                        double limite_cartao) {
    this->_nome_cartao = nome_cartao;
    this->_numero_cartao = numero_cartao;
    this->_limite_cartao = limite_cartao;
}

std::string cdcexcp::LimiteInvalido::getNomeCartao() {
    return this->_nome_cartao;
}

std::string cdcexcp::LimiteInvalido::getNumeroCartao() {
    return this->_numero_cartao;
}

double cdcexcp::LimiteInvalido::getLimiteCartao() {
    return this->_limite_cartao;
}

const char* cdcexcp::LimiteInvalido::what() const throw() {
    return "ERRO 🕵️: Limite inválido";
}

/*Métodos Exceção CartaoNaoEncontrado*/

cdcexcp::CartaoNaoEncontrado::CartaoNaoEncontrado(std::string nome_cartao) {
    this->_nome_cartao = nome_cartao;
}

std::string cdcexcp::CartaoNaoEncontrado::getNomeCartao() {
    return this->_nome_cartao;
}

const char* cdcexcp::CartaoNaoEncontrado::what() const throw() {
    return "ERRO 🕵️: Cartão não encontrado";
}

/*Métodos Exceção NumeroInvalido*/
cdcexcp::NumeroInvalido::NumeroInvalido(std::string numero) {
    this->_numero = numero;
}

std::string cdcexcp::NumeroInvalido::getNumero() {
    return this->_numero;
}

const char* cdcexcp::NumeroInvalido::what() const throw() {
    return "ERRO 🕵️: Número do cartão não tem 16 caracteres numéricos exatos";
}

/*Métodos Exceção CVVInvalido*/
cdcexcp::CVVInvalido::CVVInvalido(std::string CVV) {
    this->_CVV = CVV;
}

std::string cdcexcp::CVVInvalido::getCVV() {
    return this->_CVV;
}

const char* cdcexcp::CVVInvalido::what() const throw() {
    return "ERRO 🕵️: CVV do cartão não tem 3 caracteres numéricos exatos";
}

/*Métodos Exceção FechamentoInvalido*/
cdcexcp::FechamentoInvalido::FechamentoInvalido(std::string fechamento) {
    this->_fechamento = fechamento;
}

std::string cdcexcp::FechamentoInvalido::getFechamento() {
    return this->_fechamento;
}

const char* cdcexcp::FechamentoInvalido::what() const throw() {
    return "ERRO 🕵️: Fechamento do cartão não está entre os dias 1 e 31";
}

/*Métodos Exceção CartaoJaExiste*/
cdcexcp::CartaoJaExiste::CartaoJaExiste(std::string nome){
    this->_nome = nome;
}

const char* cdcexcp::CartaoJaExiste::what() const throw() {
    return "ERRO 🕵️: Cartão já existe";
}

std::string cdcexcp::CartaoJaExiste::getNome() {
    return this->_nome;
}