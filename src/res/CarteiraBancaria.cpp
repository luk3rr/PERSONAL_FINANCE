#include "CarteiraBancaria.hpp"

CarteiraBancaria::CarteiraBancaria(std::string nome, double saldo_inicial)
                                   : Carteira(nome, saldo_inicial, "CarteiraBancaria") { }

void CarteiraBancaria::adicionarCartao(CartaoDeCredito cartao) {
    /*A funcao find do map retorna o 'end' do map se não encontrar nada*/
    if (this->_cartoes.find(cartao.getNome()) == this->_cartoes.end()) {
        getCartoes().insert(std::pair<std::string, CartaoDeCredito>(cartao.getNome(), cartao));
    }
    else {
        throw cdcexcp::CartaoJaExiste(cartao.getNome());
    }
}

CarteiraBancaria::~CarteiraBancaria() { }

void CarteiraBancaria::removerCartao(std::string nome) {
    if (this->_cartoes.find(nome) == this->_cartoes.end()){
        throw cdcexcp::CartaoNaoEncontrado(nome);
    }
    getCartoes().erase(getCartoes().find(nome));
}

std::map<std::string, CartaoDeCredito> &CarteiraBancaria::getCartoes() {
    return this->_cartoes;
}

CartaoDeCredito *CarteiraBancaria::getCartaoDeCredito(std::string nome) {

    if (getCartoes().find(nome) == getCartoes().end()) {
        throw cdcexcp::CartaoNaoEncontrado(nome);
    }
    return &getCartoes().find(nome)->second;
}

void CarteiraBancaria::pagarFatura(std::string cartao) {

    CartaoDeCredito *cartaoDeCredito = getCartaoDeCredito(cartao);
    double valor_fatura = cartaoDeCredito->getTotalDespesas();

    if (valor_fatura > this->getSaldoAtual()) {
        throw ctrexcp::SaldoInsuficiente(this->getSaldoAtual(), valor_fatura);
    }
    setSaldoAtual(getSaldoAtual() - valor_fatura);

    std::list<std::shared_ptr<Despesa>>* listDespesa = cartaoDeCredito->getListaDespesas();
    for (std::shared_ptr<Despesa> despesa : *listDespesa) {

        int id = despesa->getID();
        getTransacoes().insert(std::pair<int, std::shared_ptr<Transacao>>(id, despesa));
    }

    listDespesa->clear();
}

void CarteiraBancaria::imprimirInfo() {
    
    const std::string separador = "___________________________________________";
    Utils::printColor(Foreground::f_yellow, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "CARTEIRA BANCÁRIA: ");
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

    Utils::printColorNoLine(Efeitos::bold_bright, "QUANTIDADE DE CARTÕES: ");
    std::cout << getCartoes().size() << std::endl;
    imprimirCartoes();

    Utils::printColor(Foreground::f_yellow, separador);
}

void CarteiraBancaria::imprimirCartoes() {

    for (auto &it : getCartoes()) {
        std::cout << std::endl;
        it.second.imprimirInfo();
    }
}
