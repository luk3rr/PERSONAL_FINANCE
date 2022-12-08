#include "Carteira.hpp"

Carteira::Carteira(std::string nome, double saldo_inicial) {
    if (saldo_inicial < 0) {
        throw ctrexcp::ValorInvalido(saldo_inicial, nome);
    }
    this->_nome = nome;
    this->_saldo_atual = saldo_inicial;
    this->_subtipo = "Carteira";
}

Carteira::Carteira(std::string nome, double saldo_inicial, std::string subtipo) {
    if (saldo_inicial < 0) {
        throw ctrexcp::ValorInvalido(saldo_inicial, nome);
    }
    this->_nome = nome;
    this->_saldo_atual = saldo_inicial;
    this->_subtipo = subtipo;
}

Carteira::~Carteira() { }

void Carteira::adicionarTransacao(std::shared_ptr<Transacao> transacao) {
    this->_transacoes.insert(std::pair<unsigned, std::shared_ptr<Transacao>>
        (transacao->getID(), transacao));
}

void Carteira::removerReceita(unsigned id) {
    std::shared_ptr<Transacao> receita = this->getTransacao(id);
    double valor = receita->getValor();

    if (receita->getSubtipo() == "receita") {
        setSaldoAtual(getSaldoAtual() - valor);
        this->_transacoes.erase(id);
    }
    else {
        throw trsexcp::TipoTransacaoInvalido(receita->getSubtipo());
    }
}

void Carteira::removerDespesa(unsigned id) {
    std::shared_ptr<Transacao> despesa = this->getTransacao(id);
    double valor = despesa->getValor();

    if (despesa->getSubtipo() == "despesa") {
        setSaldoAtual(getSaldoAtual() + valor);
        this->_transacoes.erase(id);
    }
    else {
        throw trsexcp::TipoTransacaoInvalido(despesa->getSubtipo());
    }
}

std::shared_ptr<Transacao> Carteira::getTransacao(unsigned id) {
    if (this->getTransacoes().find(id) == this->getTransacoes().end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);
    }
    return this->getTransacoes().find(id)->second;
}

void Carteira::ultimasTransacoes(unsigned quantidade) {
    auto it = getTransacoes().rbegin();
    for (unsigned i = 0; i < quantidade && i < getTransacoes().size(); ++i) {
        it->second->imprimirInfo();
        ++it;
    }
}

std::string Carteira::getNome() {
    return this->_nome;
}

double Carteira::getSaldoAtual() {
    return this->_saldo_atual;
}

void Carteira::setSaldoAtual(double saldo) {
    if (saldo < 0) {
        throw ctrexcp::ValorInvalido(saldo, this->getNome());
    }
    this->_saldo_atual = saldo;
}

std::map<unsigned, std::shared_ptr<Transacao>>& Carteira::getTransacoes() {
    return this->_transacoes;
}

std::string Carteira::getSubtipo() {
    return this->_subtipo;
}

void Carteira::imprimirInfo() {
    const std::string separador = "___________________________________________";
    Utils::printColor(Foreground::f_yellow, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA: ");
    std::cout << getNome() << std::endl;

    Utils::printColorNoLine(Efeitos::bold_bright, "SALDO ATUAL: ");
    std::cout << std::fixed << std::setprecision(2);
    std::string saldo = std::to_string(getSaldoAtual());
    saldo = "R$ " + saldo.substr(0, saldo.find(".") + 3);

    if (getSaldoAtual() > 0) {
        Utils::printColor(Foreground::f_green, saldo);
    }
    else if (getSaldoAtual() < 0) {
        Utils::printColor(Foreground::f_red, saldo);
    }
    else {
        std::cout << saldo << std::endl;
    }

    Utils::printColorNoLine(Efeitos::bold_bright, "QUANTIDADE DE TRANSAÇÕES: ");
    std::cout << getTransacoes().size() << std::endl;

    ultimasTransacoes(3);

    Utils::printColor(Foreground::f_yellow, separador);
}
