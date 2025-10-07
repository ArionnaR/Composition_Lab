// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#ifndef OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H

#include<string>
#include <vector>

#include "Transaction.h"

class BankAccount {
public:
    BankAccount(); // Default constructor
    BankAccount(const std::string& accNum, const std::string& accName, double bal); // Parameterized constructor

    BankAccount(const BankAccount& other); // Copy constructor
    BankAccount& operator=(const BankAccount& other); // Copy assignment constructor
    virtual ~BankAccount(); // Destructor

    // Accessor methods
    std::string GetAccountNumber() const;
    std::string GetAccountHolderName() const;
    double GetBalance() const;

    void SetAccountHolderName(const std::string& accountName); // Mutator method
    bool deposit(double amount); // Deposits money into account
    virtual bool withdraw(double amount); // Withdraws money into account
    virtual void printAccount() const;

    // Arithmetic assignment operators
    BankAccount& operator+=(double amount); // Adds amount to the current account's balance
    BankAccount& operator-=(double amount); // Subtracts amount from the current account's balance
    // Comparison operators
    bool operator==(const BankAccount& other) const; // Equality operator. Returns true if accounts are equal, false otherwise
    bool operator<(const BankAccount& other) const; // Less-than operator. Returns true if first account has a lesser balance than second, false otherwise
    bool operator>(const BankAccount& other) const; // Greater-than operator. Returns true if first accounts has a greater balance than second, false otherwise

    // Static utility functions
    static void printAccount(const BankAccount& account); // Prints the details of a BankAccount object
    static BankAccount createAccountFromInput(); // Asks user for account number, holder name, and initial balance and then creates a new BankAccount object

    void printHistory() const; // Prints details of each transaction

    static std::string getCurrentTime();

protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;
    std::vector<Transaction> transactionHistory;
};

#endif //OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H