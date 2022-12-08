#ifndef GERENCIA_CONTA_EXCP_H
#define GERENCIA_CONTA_EXCP_H

#include <exception>
#include <string>

namespace gcexcp {

    class PerfilVazio : public std::exception {
        public:
            PerfilVazio();

            const char* what() const throw();
    };
}

#endif
