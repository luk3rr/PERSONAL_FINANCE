#ifndef CARTEIRA_H
#define CARTEIRA_H

#include "Transacao.hpp"
#include "Utils.hpp"
#include "GerenciaCarteiraExcp.hpp"
#include "TransacaoExcp.hpp"
#include "CarteiraExcp.hpp"

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <memory>

class Carteira {
    private:
        std::string _nome;
        double _saldo_atual;
        std::map<unsigned, std::shared_ptr<Transacao>> _transacoes;
        std::string _subtipo;

    public:
        Carteira(std::string nome, double saldo_inicial);

        Carteira(std::string nome, double saldo_inicial, std::string subtipo);

        virtual ~Carteira();

        void ultimasTransacoes(unsigned quantidade);

        void adicionarTransacao(std::shared_ptr<Transacao> transacao);

        void removerTransacao(int id);

        std::string getNome();

        double getSaldoAtual();

        void setSaldoAtual(double saldo);

        std::map<unsigned, std::shared_ptr<Transacao>>& getTransacoes();


        std::string getSubtipo();

        virtual void imprimirInfo();
};

#endif 
