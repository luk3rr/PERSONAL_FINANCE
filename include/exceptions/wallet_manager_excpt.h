/*
 * Filename: wallet_manager_excpt.hpp
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 *
 * This file contains the declaration of the exceptions used in the wallet
 * management system.
 *
 * The exceptions are:
 * - EmptyProfile: thrown when the user tries to access a profile that does not
 *                 exist.
 */

#ifndef WALLET_MANAGER_EXCPT_H
#define WALLET_MANAGER_EXCPT_H

#include <exception>
#include <stdexcept>
#include <string>

/**
 * @brief Namespace that contains the exceptions used in the wallet management (wm)
 **/
namespace wmexcpt
{
    /**
     * @brief Exception thrown when the user tries to access a profile that does
     *        not exist.
     **/
    class EmptyProfile : public std::runtime_error
    {
        public:
            /**
             * @brief Default constructor
             **/
            EmptyProfile() noexcept;

            /**
             * @brief Default destructor
             **/
            ~EmptyProfile() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;
    };
} // namespace wmexcpt

#endif // WALLET_MANAGER_EXCPT_H
