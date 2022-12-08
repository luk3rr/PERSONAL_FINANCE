#include "GerenciaContaExcp.hpp"

/*Métodos para PerfilVazio*/
gcexcp::PerfilVazio::PerfilVazio() {}

const char* gcexcp::PerfilVazio::what() const throw() {
    return "ERRO 🕵️: Ainda não existem carteiras cadastradas";
}
