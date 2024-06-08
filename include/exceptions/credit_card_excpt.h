/*
 * Filename: credit_card_excpt.h
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the declaration of the exceptions used in the credit card
 * system.
 *
 * The exceptions are:
 * - LimitExceeded: thrown when the user tries to make a purchase that exceeds
 *                  the card limit.
 *
 * - InvalidLimit: thrown when the user tries to create a card with an invalid
 *                 limit.
 *
 * - CardNotFound: thrown when the user tries to access a card that does not
 *                 exist.
 *
 * - InvalidNumber: thrown when the user tries to create a card with an invalid
 *                  number.
 *
 * - InvalidCVV: thrown when the user tries to create a card with an invalid CVV.
 *
 * - InvalidClosingDate: thrown when the user tries to create a card with an
 *                       invalid closing date.
 *
 * - CardAlreadyExists: thrown when the user tries to create a card that already
 *                      exists.
 */

#ifndef CREDIT_CARD_EXCPT_H
#define CREDIT_CARD_EXCPT_H

#include <cmath>
#include <exception>
#include <stdexcept>
#include <string>

/**
 * @brief Namespace that contains the exceptions used in the credit card (cdc) system.
 **/
namespace cdcexcpt
{
    /**
     * @brief Exception thrown when the user tries to make a purchase that exceeds
     * the card limit.
     **/
    class LimitExceeded : public std::runtime_error
    {
        private:
            std::string m_cardName;
            std::string m_cardNumber;
            double_t    m_cardLimit;
            double_t    m_currentExpensesSum;

        public:
            /**
             * @brief Construct a new Limit Exceeded object
             */
            LimitExceeded(std::string cardName,
                          std::string cardNumber,
                          double_t    cardLimit,
                          double_t    currentExpensesSum) noexcept;

            /**
             * @brief Default destructor
             **/
            ~LimitExceeded() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The name of the card that exceeded the limit
             **/
            std::string GetCardName() const noexcept;

            /**
             * @return The number of the card that exceeded the limit
             **/
            std::string GetCardNumber() const noexcept;

            /**
             * @return The limit of the card that exceeded the limit
             **/
            double_t GetCardLimit() const noexcept;

            /**
             * @return The sum of the current expenses of the card that exceeded the
             *limit
             **/
            double_t GetCurrentExpensesSum() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to create a card with an invalid
     * limit.
     **/
    class InvalidLimit : public std::runtime_error
    {
        private:
            std::string m_cardName;
            std::string m_cardNumber;
            double_t    m_cardLimit;

        public:
            /**
             * @brief Construct a new Invalid Limit object
             */
            InvalidLimit(std::string cardName,
                         std::string cardNumber,
                         double_t    cardLimit) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidLimit() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The name of the card that has an invalid limit
             **/
            std::string GetCardName() const noexcept;

            /**
             * @return The number of the card that has an invalid limit
             **/
            std::string GetCardNumber() const noexcept;

            /**
             * @return The limit of the card that has an invalid limit
             **/
            double_t GetCardLimit() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to access a card that does not
     * exist.
     **/
    class CardNotFound : public std::runtime_error
    {
        private:
            std::string m_cardName;

        public:
            /**
             * @brief Construct a new Card Not Found object
             */
            CardNotFound(std::string cardName) noexcept;

            /**
             * @brief Default destructor
             **/
            ~CardNotFound() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The name of the card that was not found
             **/
            std::string GetCardName() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to create a card with an invalid
     * number.
     **/
    class InvalidNumber : public std::runtime_error
    {
        private:
            std::string m_number;

        public:
            /**
             * @brief Construct a new Invalid Number object
             */
            InvalidNumber(std::string number) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidNumber() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The invalid number
             **/
            std::string GetNumber() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to create a card with an invalid
     * CVV.
     **/
    class InvalidCVV : public std::runtime_error
    {
        private:
            std::string m_cvv;

        public:
            /**
             * @brief Construct a new Invalid CVV object
             **/
            InvalidCVV(std::string cvv) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidCVV() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The invalid CVV
             **/
            std::string GetCVV() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to create a card with an invalid
     * closing date.
     **/
    class InvalidClosingDate : public std::runtime_error
    {
        private:
            std::string m_closingDate;

        public:
            /**
             * @brief Construct a new Invalid Closing Date object
             **/
            InvalidClosingDate(std::string closingDate) noexcept;

            /**
             * @brief Default destructor
             **/
            ~InvalidClosingDate() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The invalid closing date
             **/
            std::string GetClosingDate() const noexcept;
    };

    /**
     * @brief Exception thrown when the user tries to create a card that already
     * exists.
     **/
    class CardAlreadyExists : public std::runtime_error
    {
        private:
            std::string m_name;

        public:
            /**
             * @brief Construct a new Card Already Exists object
             **/
            CardAlreadyExists(std::string name) noexcept;

            /**
             * @brief Default destructor
             **/
            ~CardAlreadyExists() noexcept;

            /**
             * @return The error message
             **/
            const char* what() const noexcept override;

            /**
             * @return The name of the card that already exists
             **/
            std::string GetName() const noexcept;
    };
} // namespace cdcexcpt

#endif // CREDIT_CARD_EXCPT_H
