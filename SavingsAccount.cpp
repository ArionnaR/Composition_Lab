// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#include "SavingsAccount.h"
#include "BankAccount.h"

#include <string>
#include <iostream>

// Constructor that calls base class constructor and initializes interest rate
SavingsAccount::SavingsAccount(const std::string& accNum, const std::string& accName, double bal, double rate) : BankAccount(accNum, accName, bal), interestRate(rate) {}

// Calculates and adds interest to balance
void SavingsAccount::calculateInterest() {
    double interest = balance * (interestRate / 100.0);
    balance += interest;
    std::cout << "Interest added: " << interest << std::endl;
}
// Override of printAccount function
void SavingsAccount::printAccount() const {
    BankAccount::printAccount();
    std::cout << "Account Type: Savings" << std::endl;
    std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
}
