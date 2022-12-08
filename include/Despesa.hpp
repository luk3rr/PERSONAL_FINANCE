#ifndef DESPESA_H
#define DESPESA_H

#include "Transacao.hpp"

#include <memory>

class Despesa : public Transacao {
    private:
        std::string _conta;

    public:
        Despesa(double valor, std::string data, std::string categoria, std::string conta);

        std::string getConta();

        void alterarConta(std::string nova_conta);

        void imprimirInfo();
};

#endif
