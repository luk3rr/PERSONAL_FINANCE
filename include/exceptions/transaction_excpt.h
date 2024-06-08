/*
 * Filename: transaction_excpt.h
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the declaration of the exceptions used in the
 * transaction module.
 *
 * The exceptions are:
 * - TransactionNotFound: thrown when a transaction with a given id is not found
 *
 * - InvalidTransactionType: thrown when a transaction type is invalid
 *
 * - InvalidDate: thrown when a date is invalid
 *
 * - SameOriginDestination: thrown when the origin and destination of a transaction
 */

#ifndef TRANSACTION_EXCPT_H
#define TRANSACTION_EXCPT_H

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <string>

#include "config.h"

/**
 * @brief Namespace that contains the exceptions used in the transaction (tsc) module
 **/
namespace tscexcpt
{
    /**
     * @brief Exception thrown when a transaction with a given id is not found
     **/
    class TransactionNotFound : public std::runtime_error
    {
        private:
            std::size_t m_id;

        public:
            /**
             * @brief Construct a new Transaction Not Found object
             **/
            TransactionNotFound(std::size_t id) noexcept;

            /**
             * @brief Default destructor
             **/
            ~TransactionNotFound() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The id of the transaction that was not found
             **/
            std::size_t GetID() const noexcept;
    };

    /**
     * @brief Exception thrown when a transaction type is invalid
     **/
    class InvalidTransactionType : public std::runtime_error
    {
        private:
            config::TransactionType m_type;

        public:
            /**
             * @brief Construct a new Invalid Transaction Type object
             **/
            InvalidTransactionType(config::TransactionType type) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidTransactionType() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The invalid transaction type
             **/
            config::TransactionType GetType() const noexcept;
    };

    /**
     * @brief Exception thrown when a date is invalid
     **/
    class InvalidDate : public std::runtime_error
    {
        private:
            std::string m_date;

        public:
            /**
             * @brief Construct a new Invalid Date object
             **/
            InvalidDate(std::string date) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidDate() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The invalid date
             **/
            std::string GetDate() const noexcept;
    };

    /**
     * @brief Exception thrown when the origin and destination of a transaction are the
     *same
     **/
    class SameOriginDestination : public std::runtime_error
    {
        private:
            std::string m_originDestination;

        public:
            /**
             * @brief Construct a new Same Origin Destination object
             **/
            SameOriginDestination(std::string originDestination) noexcept;

            /**
             * @brief Default destructor
             **/
            ~SameOriginDestination() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The origin and destination that are the same
             **/
            std::string GetOriginDestination() const noexcept;
    };
} // namespace tscexcpt

#endif // TRANSACTION_EXCPT_H
