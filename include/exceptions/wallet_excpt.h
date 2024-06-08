/*
 * Filename: wallet_excpt.hpp
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the declaration of the exceptions used in the Wallet
 * class.
 *
 * The exceptions are:
 * - InvalidValue: thrown when a value is invalid.
 *
 * - AccountNotFound: thrown when an account is not found.
 *
 * - AccountAlreadyExists: thrown when an account already exists.
 *
 * - AccountDoesNotAllowCard: thrown when an account does not allow a card.
 *
 * - InsufficientBalance: thrown when an account has insufficient balance.
 */

#ifndef WALLET_EXCPT_H
#define WALLET_EXCPT_H

#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>

/**
 * @brief Namespace that contains the exceptions used in the Wallet (wlt) class.
 **/
namespace wltexcpt
{
    /**
     * @brief Exception thrown when a value is invalid.
     **/
    class InvalidValue : public std::runtime_error
    {
        private:
            double_t    m_value;
            std::string m_walletName;

        public:
            /**
             * @brief Construct a new Invalid Value object
             **/
            InvalidValue(double value, std::string walletName) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidValue() noexcept;

            /**
             * @return The error message
             */
            const char* what() const noexcept override;

            /**
             * @return The invalid value
             **/
            double_t GetValue() const noexcept;

            /**
             * @return The wallet name
             **/
            std::string GetName() const noexcept;
    };

    /**
     * @brief Exception thrown when an account is not found.
     **/
    class AccountNotFound : public std::runtime_error
    {
        private:
            std::string m_name;

        public:
            /**
             * @brief Construct a new Account Not Found object
             **/
            AccountNotFound(std::string name) noexcept;

            /**
             * @brief Default destructor
             **/
            ~AccountNotFound() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The account name
             **/
            std::string GetName() const noexcept;
    };

    /**
     * @brief Exception thrown when an account already exists.
     **/
    class AccountAlreadyExists : public std::runtime_error
    {
        private:
            std::string m_name;

        public:
            /**
             * @brief Construct a new Account Already Exists object
             **/
            AccountAlreadyExists(std::string name) noexcept;

            /**
             * @brief Default destructor
             **/
            ~AccountAlreadyExists() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The account name
             **/
            std::string GetName() const noexcept;
    };

    /**
     * @brief Exception thrown when an account does not allow a card.
     **/
    class AccountDoesNotAllowCard : public std::runtime_error
    {
        private:
            std::string m_accountName;
            std::string m_accountSubtype;

        public:
            /**
             * @brief Construct a new Account Does Not Allow Card object
             **/
            AccountDoesNotAllowCard(std::string accountName,
                                    std::string accountSubtype) noexcept;

            /**
             * @brief Default destructor
             **/
            ~AccountDoesNotAllowCard() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The account name
             **/
            std::string GetAccountName() const noexcept;

            /**
             * @return The account subtype
             **/
            std::string GetAccountSubtype() const noexcept;
    };

    /**
     * @brief Exception thrown when an account has insufficient balance.
     **/
    class InsufficientBalance : public std::runtime_error
    {
        private:
            double_t m_balance;
            double_t m_expense;

        public:
            /**
             * @brief Construct a new Insufficient Balance object
             **/
            InsufficientBalance(double balance, double expense) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InsufficientBalance() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The balance
             **/
            double_t GetBalance() const noexcept;

            /**
             * @return The expense
             **/
            double_t GetExpense() const noexcept;
    };
} // namespace wltexcpt

#endif // WALLET_EXCPT_H
