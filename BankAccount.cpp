// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#include "BankAccount.h"

#include <cstring>
#include <iostream>
#include <ctime>

// Default constructor with initialized placeholder values
BankAccount::BankAccount() {
    accountNumber = "-1";
    accountHolderName = "NoName";
    balance = 0.0;
}
// Parameterized constructor with initialized values
BankAccount::BankAccount(const std::string& accNum, const std::string& accName, double bal) {
    accountNumber = accNum;
    accountHolderName = accName;
    balance = bal;
}
// Copy constructor creating new object by copying another
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;
}
// Copy assignment operator assigning existing object values to another
BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;
    }
    return *this;
}
BankAccount::~BankAccount() { // Destructor
}

std::string BankAccount::GetAccountNumber() const { // Getter for account number
    return accountNumber;
}
std::string BankAccount::GetAccountHolderName() const { // Getter for account holder name
    return accountHolderName;
}
double BankAccount::GetBalance() const { // Getter for balance
    return balance;
}
void BankAccount::SetAccountHolderName(const std::string& accountName) { // Setter for acount holder name
    accountHolderName = accountName;
}
bool BankAccount::deposit(double amount) { // Deposit function
    if (amount > 0) {
        balance += amount;
        // Creates and adds transaction to history
        transactionHistory.emplace_back("Deposit", amount, BankAccount::getCurrentTime());
        return true;
    }
    else {
        return false;
    }
}
bool BankAccount::withdraw(double amount) { // Withdraw function
    if (amount <= balance) {
        balance -= amount;
        // Creates and adds transaction to history
        transactionHistory.emplace_back("Withdrawal", amount, BankAccount::getCurrentTime());
        return true;
    }
    else {
        return false;
    }
}

BankAccount& BankAccount::operator+=(double amount) { // Adds amount to current amount
    deposit(amount);
    return *this;
}
BankAccount& BankAccount::operator-=(double amount) { // Subtracts amount from current amount
    withdraw(amount);
    return *this;
}
bool BankAccount::operator==(const BankAccount& other) const { // Returns true if two accounts have same account number, false otherwise
    return accountNumber == other.accountNumber;
}
bool BankAccount::operator<(const BankAccount& other) const { // Returns true if first account has less balance than other, false otherwise
    return balance < other.balance;
}
bool BankAccount::operator>(const BankAccount& other) const { // Returns true if first account has greater balance than other, false otherwise
    return balance > other.balance;
}
// Prints account details
void BankAccount::printAccount() const {
    std::cout << "Account Number: " << GetAccountNumber() << std::endl;
    std::cout << "Account Holder Name: " << GetAccountHolderName() << std::endl;
    std::cout << "Balance: " << GetBalance() << std::endl;
}

void BankAccount::printAccount(const BankAccount &account) {
    account.printAccount();
}


BankAccount BankAccount::createAccountFromInput() { // Gets input from user to create account
    std::string accNum;
    std::string accName;
    double bal;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter Account Holder Name: ";
    std::cin >> accName;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter Balance: ";
    std::cin >> bal;
    // Validates input
    while (std::cin.fail() || bal < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid balance. Try again: ";
        std::cin >> bal;
    }
    return BankAccount(accNum, accName, bal); // Returns new BankAccount
}
// Views transaction history
void BankAccount::printHistory() const {
    if (transactionHistory.empty()) {
        std::cout << "Empty transaction history" << std::endl;
        return;
    }
    std::cout << "Transaction History:" << std::endl;
    for (const auto& transaction : transactionHistory) {
        std::cout << transaction.GetTimestamp() << " - " << transaction.GetType() << ": " << transaction.GetAmount() << std::endl;
    }
}

std::string BankAccount::getCurrentTime() { // Gets the current time
    time_t now = time(0);
    char* currentTime = ctime(&now);
    currentTime[strlen(currentTime) - 1] = '\0';
    return std::string(currentTime);
}