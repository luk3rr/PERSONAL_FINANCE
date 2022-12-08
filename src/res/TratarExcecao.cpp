#include "TratarExcecao.hpp"
#include "CartaoDeCreditoExcp.hpp"
#include "CarteiraExcp.hpp"
#include "TransacaoExcp.hpp"
#include "GerenciaContaExcp.hpp"

#include <exception>

enum {
    a,
    b
};

void TratarExcecao(std::exception &e) {

    if (ctrexcp::ValorInvalido == e) {
        Utils::printColor(Foreground::f_red, e.what());
        Utils::printColorNoLine(Foreground::f_red, "SALDO: "); 
        std::cout << e.getValor() << std::endl;
    }
    catch (ctrexcp::ContaJaExiste &e) {
        Utils::printColor(Foreground::f_red, e.what());
        Utils::printColorNoLine(Foreground::f_red, "CONTA: "); 
        std::cout << e.getNome() << std::endl;
    }
}
