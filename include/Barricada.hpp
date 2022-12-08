#ifndef BARRICADA_H
#define BARRICADA_H

#include "TransacaoExcp.hpp"
#include "CartaoDeCreditoExcp.hpp"
#include "Utils.hpp"
#include "CarteiraExcp.hpp"

#define PIB_MUNDIAL 96000000000000

#include <iostream>
#include <limits>
#include <regex>


class Barricada {
    private:
        static const std::string NUMERO_CC_VALIDO;
        static const std::string CVV_VALIDO;
        static const std::string FECHAMENTO_CC_VALIDO;
        static const std::string DATA_VALIDA;

    public:
        static void validar_saldo(double &saldo);

        static void validar_input(unsigned &input);

        static void validar_transacao(double &valor_transacao);

        static void validar_id(unsigned &id);

        static void validar_limite_cartao(double &limite);

        static bool validar_cartao(std::string numero, std::string CVV,
                                   std::string fechamento);
        
        static bool validar_transferencia(std::string data, std::string origem,
                                          std::string destino);
                                          
        static bool validar_data(std::string data);

        
};

#endif
