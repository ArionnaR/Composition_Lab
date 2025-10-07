// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#ifndef INHERITANCE_LAB_CHECKINGACCOUNT_H
#define INHERITANCE_LAB_CHECKINGACCOUNT_H
#include "BankAccount.h"

// Publicly inherits from BankAccount
class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const std::string& accNum, const std::string& accName, double bal, double fee); // Constructor
    bool withdraw(double amount) override; // Overrides withdraw function
    void printAccount() const override; // Prints account details

private:
    double transactionFee;
};


#endif //INHERITANCE_LAB_CHECKINGACCOUNT_H