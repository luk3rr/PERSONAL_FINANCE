#include "GerenciaConta.hpp"


GerenciaConta::GerenciaConta() { }

std::map<std::string, std::shared_ptr<Carteira>>& GerenciaConta::getContas() {
    return this->_contas;
}

std::shared_ptr<Carteira> GerenciaConta::getConta(std::string nome) {

    if (getContas().find(nome) == getContas().end()) {
        throw ctrexcp::ContaNaoEncontrada(nome);
    }

    else {
        return getContas().find(nome)->second;
    }
}

void GerenciaConta::adicionarCarteira(std::string nome, double saldo_inicial) {

    if (getContas().find(nome) == getContas().end()) {
        std::shared_ptr<Carteira> carteira = std::make_shared<Carteira>(nome, saldo_inicial);
        this->_contas.insert(std::pair<std::string, std::shared_ptr<Carteira>>(nome, carteira));
    }

    else {
        throw ctrexcp::ContaJaExiste(nome);
    }
}

void GerenciaConta::adicionarConta(std::string nome, double saldo_inicial) {

    if (getContas().find(nome) == getContas().end()) {
        std::shared_ptr<CarteiraBancaria> conta = std::make_shared<CarteiraBancaria>(nome, saldo_inicial);
        this->_contas.insert(std::pair<std::string, std::shared_ptr<Carteira>>(nome, conta));
    }
    else {
        throw ctrexcp::ContaJaExiste(nome);
    }
}

void GerenciaConta::removerConta(std::string nome) {

    /*A funcao 'find' de um map retorna um ponteiro para map.end se nao encontrar nada*/
    if (this->getContas().find(nome) == this->getContas().end()) {
        throw ctrexcp::ContaNaoEncontrada(nome);
    }

    this->_contas.erase(this->_contas.find(nome));
}

void GerenciaConta::adicionarReceita(std::string conta, double valor, std::string data, std::string categoria) {

    Barricada::validar_data(data);
    
    std::shared_ptr<Receita> receita = std::make_shared<Receita>(conta, valor, data, categoria);
    getConta(conta)->adicionarTransacao(receita);
}

void GerenciaConta::adicionarDespesa(std::string conta, double valor, std::string data, std::string categoria) {

    Barricada::validar_data(data);

    std::shared_ptr<Despesa> despesa = std::make_shared<Despesa>(valor, data, categoria, conta);
    getConta(conta)->adicionarTransacao(despesa);
}

void GerenciaConta::adicionarDespesaCartao(std::string conta, std::string cartao, double valor, std::string data, std::string categoria) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {
        Barricada::validar_data(data);

        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));
        conta_bancaria->getCartaoDeCredito(cartao)->adicionarDespesa(valor, data, categoria);
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(conta, getConta(conta)->getSubtipo());
    }
}

void GerenciaConta::adicionarTransferencia(double valor, std::string data, std::string categoria,   
                                           std::string origem, std::string destino) {

    Barricada::validar_transferencia(data, origem, destino);

    std::shared_ptr<Transferencia> transferencia = std::make_shared<Transferencia>
                                               (valor, data, categoria, origem, destino);

    std::shared_ptr<Carteira> conta_origem = getConta(origem);
    std::shared_ptr<Carteira> conta_destino = getConta(destino);

    conta_origem->setSaldoAtual(conta_origem->getSaldoAtual() - valor);
    conta_destino->setSaldoAtual(conta_destino->getSaldoAtual() + valor);

    conta_origem->adicionarTransacao(transferencia);
    conta_destino->adicionarTransacao(transferencia);

}

void GerenciaConta::removerReceita(std::string conta, int id) {

    if (getConta(conta)->getTransacoes().find(id) == getConta(conta)->getTransacoes().end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);       
    }

    else if (getConta(conta)->getTransacoes().find(id)->second->getSubtipo() == "despesa") {
        throw trsexcp::TipoTransacaoInvalido("despesa");
    }
 
    else {
        getConta(conta)->removerTransacao(id);
    }
}

void GerenciaConta::removerDespesa(std::string conta, int id) {

    if (getConta(conta)->getTransacoes().find(id) == getConta(conta)->getTransacoes().end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);       
    }

    else if (getConta(conta)->getTransacoes().find(id)->second->getSubtipo() == "receita") {
        throw trsexcp::TipoTransacaoInvalido("receita");
    }
 
    else {
        getConta(conta)->removerTransacao(id);
    }
}

void GerenciaConta::removerDespesaCartao(std::string conta, std::string cartao, int id) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));
        conta_bancaria->getCartoes().find(cartao)->second.removerDespesa(id);
    }
}

void GerenciaConta::removerTransferencia(std::string conta, int id) {
    std::shared_ptr<Carteira> cart = getConta(conta);

    if (cart->getTransacoes().find(id) == cart->getTransacoes().end()) {
        throw trsexcp::TransacaoNaoEncontrada(id);
    }

    std::shared_ptr<Transacao> transacao = cart->getTransacoes().find(id)->second;

    if (transacao->getSubtipo() != "transferencia") {
        throw trsexcp::TipoTransacaoInvalido(transacao->getSubtipo());
    }

    std::shared_ptr<Transferencia> transferencia;
    transferencia = std::dynamic_pointer_cast<Transferencia>(cart->getTransacoes().find(id)->second);

    std::shared_ptr<Carteira> conta_origem = this->getConta(transferencia->getOrigem());
    std::shared_ptr<Carteira> conta_destino = this->getConta(transferencia->getDestino());
    
    // Eh necessario verificar se ha saldo suficiente na conta de destino,
    // caso contrario a conta poderia ficar com saldo negativo
    if (conta_destino->getSaldoAtual() < transferencia->getValor()) {
        throw ctrexcp::SaldoInsuficiente(conta_destino->getSaldoAtual(), transferencia->getValor());
    }

    conta_origem->setSaldoAtual(conta_origem->getSaldoAtual() + transferencia->getValor());
    conta_destino->setSaldoAtual(conta_destino->getSaldoAtual() - transferencia->getValor());

    conta_origem->getTransacoes().erase(id);
    conta_destino->getTransacoes().erase(id);
}

void GerenciaConta::adicionarCartao(std::string conta, std::string nome,
                                    std::string numero, std::string CVV,
                                    std::string fechamento, double limite_cartao) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {

        Barricada::validar_cartao(numero, CVV, fechamento);

        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));

        CartaoDeCredito cartao_de_credito(nome, numero, CVV, fechamento, limite_cartao);
        conta_bancaria->adicionarCartao(cartao_de_credito);

    } else {
        throw ctrexcp::ContaNaoPermiteCartao(conta, getConta(conta)->getSubtipo());
    }
}

void GerenciaConta::removerCartao(std::string conta, std::string cartao) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));

        conta_bancaria->removerCartao(cartao);
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(conta, getConta(conta)->getSubtipo());
    }
}

void GerenciaConta::pagarFaturaCartao(std::string conta, std::string cartao) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));

        conta_bancaria->pagarFatura(cartao);
    }
    else {
        // TO DO: Ser possivel pagar fatura do cartao com uma carteira
        throw ctrexcp::ContaNaoPermiteCartao(conta, getConta(conta)->getSubtipo());
    }
}

void GerenciaConta::listarDespesasCartao(std::string conta, std::string cartao) {

    if (getConta(conta)->getSubtipo() == "CarteiraBancaria") {
        std::shared_ptr<CarteiraBancaria> conta_bancaria;
        conta_bancaria = std::dynamic_pointer_cast<CarteiraBancaria>(getConta(conta));

        conta_bancaria->getCartaoDeCredito(cartao)->listarDespesas();
    }
    else {
        throw ctrexcp::ContaNaoPermiteCartao(conta, getConta(conta)->getSubtipo());
    }
}

void GerenciaConta::imprimirContas() {
    if(!(getContas().empty())) {
        for (auto const& conta : getContas()) {
            conta.second->imprimirInfo();
        }
    } 
    else {
        throw gcexcp::PerfilVazio();
    }
}

void GerenciaConta::listarTransacao(std::string conta, std::string tipo) {

    //transforma os caracteres da string em minúsculo
    std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);

    if (tipo == "despesa" || tipo == "receita" || tipo == "transferencia") {
        std::shared_ptr<Carteira> cart_conta = getConta(conta);

        Utils::printColorNoLine(Efeitos::bold_bright, "CONTA: ");
        Utils::printColorNoLine(Efeitos::bold_bright, cart_conta->getNome());

        int i = 0;
        for (auto const& it : getConta(conta)->getTransacoes()) {
            if (it.second->getSubtipo() == tipo) {
                std::cout << std::endl; 
                it.second->imprimirInfo();
                ++i;
            }   
        }

        if (i == 0) {
            std::cout << std::endl;
            Utils::printColor(Foreground::f_yellow, "Nenhuma " + tipo + " encontrada");
        }
    }
    else {
        throw trsexcp::TipoTransacaoInvalido(tipo);
    }
}
