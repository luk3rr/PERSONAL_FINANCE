/*
 * Filename: barricade.h
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the declaration of the Barricade class.
 *
 * The Barricade class is responsible for validating user input and
 * throwing exceptions when the input is invalid.
 */

#ifndef BARRICADE_H
#define BARRICADE_H

#include "credit_card_excpt.h"
#include "transaction_excpt.h"
#include "utils.h"
#include "wallet_excpt.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <regex>
#include <sstream>
#include <vector>

/**
 * @brief This class is responsible for validating user input and throwing
 * exceptions when the input is invalid.
 **/
class Barricade
{
    private:
        static const std::string VALID_TYPE, VALID_CC_NUMBER, VALID_CVV,
            VALID_CC_CLOSURE, VALID_DATE;

    public:
        static void validateMenuOption(unsigned& input);

        static void validateAmount(double& amount);

        static void validateID(unsigned& id);

        static void validateCardNumber(std::string& number);

        static void validateCardCvv(std::string& CVV);

        static void validateCardClosure(std::string& closure);

        static void validateOriginDestination(std::string& origin,
                                              std::string& destination);

        static void validateDate(std::string& date);

        static void validateType(std::string& type);
};

#endif
