/*
 * Filename: wallet_manager.h
 * Created on: June  6, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 *
 * This file contains the WalletManager class declaration.
 *
 * The WalletManager class is responsible for managing the Wallets and their
 * transactions. It is responsible for creating, removing, and listing Wallets,
 * as well as adding, removing, and listing transactions.
 */

#ifndef WALLET_MANAGER_H
#define WALLET_MANAGER_H

#include "bank_wallet.h"
#include "barricade.h"
#include "credit_card.h"
#include "expense.h"
#include "income.h"
#include "input_validation.h"
#include "transaction_excpt.h"
#include "transfer.h"
#include "wallet.h"
#include "wallet_excpt.h"
#include "wallet_manager_excpt.h"

#include <algorithm>
#include <cctype>
#include <map>
#include <memory>

/**
 * @brief The WalletManager class is responsible for managing the Wallets and
 * their transactions.
 *
 * The WalletManager class is responsible for creating, removing, and listing
 * Wallets, as well as adding, removing, and listing transactions.
 **/
class WalletManager
{
    private:
        std::map<std::string, Wallet*> m_wallets;

    public:
        WalletManager();

        std::map<std::string, Wallet*>& GetWallets();

        Wallet* GetWallet(std::string name);

        void AddWallet(std::string name, double initial_balance);

        void RemoveWallet(std::string name);

        void AddIncome(std::string account,
                       double      value,
                       std::string date,
                       std::string category);

        void AddExpense(std::string account,
                        double      value,
                        std::string date,
                        std::string category);

        void AddCardExpense(std::string account,
                            std::string card,
                            double      value,
                            std::string date,
                            std::string category);

        void addTransfer(double      value,
                         std::string date,
                         std::string category,
                         std::string source,
                         std::string destination);

        void RemoveIncome(std::string account, unsigned id);

        void RemoveExpense(std::string account, unsigned id);

        void RemoveCardExpense(std::string account, std::string card, unsigned id);

        void RemoveTransfer(std::string account, unsigned id);

        void AddCard(std::string account,
                     std::string name,
                     std::string number,
                     std::string CVV,
                     std::string closing,
                     double      card_limit);

        void RemoveCard(std::string account, std::string card);

        void PayCardBill(std::string account, std::string card);

        void ListCardExpenses(std::string account, std::string card);

        void PrintWallets();

        void ListTransactions(std::string account, std::string type);
};

#endif
