/*
 * Filename: input_validation.h
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the declaration of the InputValidation class.
 *
 * The InputValidation class is responsible for validating the input of the user
 * in the application.
 */

#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include "credit_card_excpt.h"
#include "transaction_excpt.h"
#include "wallet_excpt.h"

#include <cstdarg>
#include <regex>
#include <string>

/**
 * @brief This class is responsible for validating the input of the user in the
 * application.
 **/
class InputValidation
{
    private:
        static const std::string VALID_TYPE, VALID_CC_NUMBER, VALID_CVV,
            VALID_CC_CLOSING, VALID_DATE;

    public:
        static void value(double& value);

        static void creditCardNumber(std::string& number);

        static void creditCardCVV(std::string& CVV);

        static void creditCardClosing(std::string& closing);

        static void originDestination(std::string& origin, std::string& destination);

        static void date(std::string& date);
};

#endif // !INPUT_VALIDATION_H
