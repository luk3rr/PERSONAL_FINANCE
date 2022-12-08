#include "Despesa.hpp"

Despesa::Despesa(double valor, std::string data, std::string categoria,
        std::string conta) : Transacao(valor, data, categoria, "despesa") {
    this->_conta = conta;
}

std::string Despesa::getConta() {
    return this->_conta;
}

void Despesa::alterarConta(std::string nova_conta) {
    this->_conta = nova_conta;
}

void Despesa::imprimirInfo() {
    const std::string separador = "\t___________________________________";

    Utils::printColor(Foreground::f_red, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tID DA DESPESA: ");
    std::cout << getID() << std::endl;

    if (getSubtipo() == "CarteiraBancaria") {
        Utils::printColorNoLine(Efeitos::bold_bright, "\tCARTEIRA BANCÁRIA: ");
        std::cout << getConta() << std::endl;
    }
    else if (getSubtipo() == "Carteira") {
        Utils::printColorNoLine(Efeitos::bold_bright, "\tCARTEIRA: ");
        std::cout << getConta() << std::endl;
    }
    
    Utils::printColorNoLine(Efeitos::bold_bright, "\tVALOR: ");
    std::string valor = std::to_string(getValor());
    valor  = "R$ " + valor.substr(0, valor.find(".") + 3);
    Utils::printColor(Foreground::f_red, valor);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tDATA: ");
    std::cout << getData() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCATEGORIA: ");
    std::cout << getCategoria() << std::endl;

    Utils::printColor(Foreground::f_red, separador);
}
