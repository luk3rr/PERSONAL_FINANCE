#include "Receita.hpp"

Receita::Receita(std::string conta, double valor, std::string data,
        std::string categoria) : Transacao(valor, data, categoria, "receita") {
    this->_conta = conta;
}

void Receita::alterarConta(std::string conta_destino) {
    this->_conta = conta_destino;
}

std::string Receita::getConta() {
    return this->_conta;
}

void Receita::imprimirInfo() {
    const std::string separador = "\t___________________________________";

    Utils::printColor(Foreground::f_green, separador);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tID DA RECEITA: ");
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
    Utils::printColor(Foreground::f_green, valor);

    Utils::printColorNoLine(Efeitos::bold_bright, "\tDATA: ");
    std::cout << getData() << std::endl;
    Utils::printColorNoLine(Efeitos::bold_bright, "\tCATEGORIA: ");
    std::cout << getCategoria() << std::endl;

    Utils::printColor(Foreground::f_green, separador);
}
