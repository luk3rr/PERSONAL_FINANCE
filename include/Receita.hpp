#ifndef RECEITA_H
#define RECEITA_H

#include "Transacao.hpp"

#include <string>

class Receita : public Transacao {
    private:
        std::string _conta;

    public:
        Receita(std::string conta, double valor, std::string data, std::string categoria);

        void alterarConta(std::string conta_destino);

        std::string getConta();

        void imprimirInfo();
};

#endif
