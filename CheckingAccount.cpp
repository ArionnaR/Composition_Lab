// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#include "CheckingAccount.h"
#include <iostream>

// Constructor that calls base class constructor and initializes transaction fee
CheckingAccount::CheckingAccount(const std::string& accNum, const std::string& accName, double bal, double fee) : BankAccount(accNum, accName, bal), transactionFee(fee)  {}

// Override of withdraw function
bool CheckingAccount::withdraw(double amount) {
    double total = amount + transactionFee;
    if (total <= balance) {
        balance -= total;
        transactionHistory.emplace_back("Withdrawal", amount, BankAccount::getCurrentTime());
        return true;
    }
    else {
        std::cout << "Insufficient funds" << std::endl;
        return false;
    }
}
// Override of printAccount function
void CheckingAccount::printAccount() const {
    BankAccount::printAccount();
    std::cout << "Account Type: Checking" << std::endl;
    std::cout << "Transaction Fee: " << transactionFee << std::endl;
}