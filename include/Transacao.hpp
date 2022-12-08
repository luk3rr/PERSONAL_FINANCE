#ifndef TRANSACAO_H
#define TRANSACAO_H

#include "Utils.hpp"

#include <string>

class Transacao {
    private:
        static int _contador;
        int _id;
        double _valor;
        std::string _data, _categoria, _subtipo;

    public:
        Transacao(double valor, std::string data, std::string categoria, 
            std::string subtipo);

        double getValor();

        std::string getData();

        std::string getCategoria();

        std::string getSubtipo();

        int getID();

        virtual void imprimirInfo() = 0;
};

#endif // !TRANSACAO
