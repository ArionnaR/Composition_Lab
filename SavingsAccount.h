// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#ifndef INHERITANCE_LAB_SAVINGSACCOUNT_H
#define INHERITANCE_LAB_SAVINGSACCOUNT_H

#include "BankAccount.h"

// Publicly inherits from BankAccount
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const std::string& accNum, const std::string& accName, double bal, double rate); // Constructor
    void calculateInterest(); // Adds interest to balance
    void printAccount() const override; // Prints account details

private:
    double interestRate;
};


#endif //INHERITANCE_LAB_SAVINGSACCOUNT_H