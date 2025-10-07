// Arionna Rogers
// 9/29/25
// Extend Bank Account System to support different types of accounts, such as Checking and Savings Accounts
// Lab Activities: Inheritance

#include <iostream>
#include <memory>
#include <vector>
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

// Function declarations
int displayMenu();
std::unique_ptr<BankAccount> createAccount();
void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts);

int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts; // Vector stores multiple accounts
    runMenu(accounts); // Runs the menu
    return 0;
}
int displayMenu() { // Displays menu and gets user's choice
    std::cout << "\nMenu\n";
    std::cout << "1. Enter Account Info\n";
    std::cout << "2. View Account Info\n";
    std::cout << "3. Deposit\n";
    std::cout << "4. Withdraw\n";
    std::cout << "5. Compare Accounts\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. Quit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) { // Checks invalid input
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        return -1;
    }
    return choice;
}
std::unique_ptr<BankAccount> createAccount() { // Creates  account
    int accType = 0;

    while (true) {
        std::cout << "Choose Account Type:\n";
        std::cout << "1. Checking Account\n";
        std::cout << "2. Savings Account\n";
        std::cout << "Enter choice: \n";
        std::cin >> accType;

        if (std::cin.fail() || (accType != 1 && accType != 2)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid Input. Try again.\n";
        }
        else {
            break;
        }
    }

    std::string accNum;
    std::string accName;
    double bal;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter Account Holder Name: ";
    std::getline(std::cin, accName);

    std::cout << "Enter Account Balance: ";
    std::cin >> bal;

    while (std::cin.fail() || bal < 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid balance. Try again: ";
        std::cin >> bal;
    }
    // Creates Checking or Savings account based on choice
    if (accType == 1) {
        double fee;
        std::cout << "Enter Transaction Fee: ";
        std::cin >> fee;

        while (std::cin.fail() || fee < 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid fee. Try again: ";
            std::cin >> fee;
        }

        return std::make_unique<CheckingAccount>(accNum, accName, bal, fee);
    }
    else if (accType == 2) {
        double rate;
        std::cout << "Enter Interest Rate (5 for 5%): ";
        std::cin >> rate;

        while (std::cin.fail() || rate < 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid rate. Try again: ";
            std::cin >> rate;
        }

        auto savings = std::make_unique<SavingsAccount>(accNum, accName, bal, rate);
        savings->calculateInterest();
        return savings;
    }
    return nullptr;
}

void runMenu(std::vector<std::unique_ptr<BankAccount>>& accounts) {
    int choice;
    int i;
    int index;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: { // Choice 1 to create account
                if (auto acc = createAccount()) {
                    accounts.push_back(std::move(acc));
                    std::cout << "Account entered." << std::endl;
                }
                break;
            }
            case 2: // Choice 2 that views accounts
                if (accounts.empty()) {
                    std::cout << "No Account found." << std::endl;
                }
                else {
                    std::cout << "Account Info:\n";
                    for (i = 0; i < static_cast<int>(accounts.size()); ++i) {
                        std::cout << (i + 1) << ".\n";
                        BankAccount::printAccount(*accounts[i]);
                        std::cout << std::endl;
                    }
                }
                break;

            case 3: // Choice 3 that deposits into account
                if (accounts.empty()) {
                    std::cout << "No Account found." << std::endl;
                    break;
                } // Displays accounts
                std::cout << "Accounts:\n";
                for (i = 0; i < static_cast<int>(accounts.size()); ++i) {
                    std::cout << (i + 1) << ".\n";
                    BankAccount::printAccount(*accounts[i]);
                    std::cout << std::endl;
                }
                while (true) { // Asks user to choose account index
                    std::cout << "Choose account to deposit into: ";
                    std::cin >> index;
                    if (std::cin.fail() || index < 1 || index > static_cast<int>(accounts.size())) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid account. Try again.\n";
                    }
                    else {
                        index -= 1;
                        break;
                    }
                }
                double amount; // Asks for deposit amount
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;

                while (std::cin.fail() || amount <= 0) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid deposit amount. Try again: ";
                    std::cin >> amount;
                }
                *accounts[index] += amount;
                std::cout << "Deposited: " << amount << std::endl;
                break;
            case 4: // Choice 4 to withdraw into account
                if (accounts.empty()) {
                    std::cout << "No Account found." << std::endl;
                    break;
                }
                std::cout << "Accounts:\n";
                for (i = 0; i < static_cast<int>(accounts.size()); ++i) {
                    std::cout << (i + 1) << ".\n";
                    BankAccount::printAccount(*accounts[i]);
                    std::cout << std::endl;
                }
                while (true) { // Asks user to choose account
                    std::cout << "Choose account to withdraw from: ";
                    std::cin >> index;
                    if (std::cin.fail() || index < 1 || index > static_cast<int>(accounts.size())) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid account. Try again: ";
                    }
                    else {
                        index -= 1;
                        break;
                    }
                } // Asks for withdrawal amount
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;

                while (std::cin.fail() || amount <= 0) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "Invalid withdrawal amount. Try again: ";
                    std::cin >> amount;
                }
                if (accounts[index]->GetBalance() >= amount) { // Makes sure withdrawal is within balance
                    *accounts[index] -= amount;
                    std::cout << "Withdrawn: " << amount << std::endl;
                }
                else {
                    std::cout << "Withdrawal amount exceeds balance." << std::endl;
                }
                break;
                case 5: { // Choice 5 to compare accounts
                    if (accounts.size() < 2) {
                        std::cout << "Need 2 accounts to compare.\n";
                        break;
                    }
                    std::cout << "Accounts:\n";
                    for (i = 0; i < static_cast<int>(accounts.size()); ++i) {
                        std::cout << (i + 1) << ".\n";
                        BankAccount::printAccount(*accounts[i]);
                        std::cout << std::endl;
                    } // Get user input for 2 accounts
                    int index1;
                    int index2;
                    std::cout << "Enter first account index: ";
                    std::cin >> index1;
                    std::cout << "Enter second account index: ";
                    std::cin >> index2;

                    if (std::cin.fail() || index1 < 1 || index2 < 1 || index1 > static_cast<int>(accounts.size()) || index2 > static_cast<int>(accounts.size())) {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Invalid accounts. Try again.\n";
                        break;
                    }
                    index1 -= 1;
                    index2 -= 1;

                    BankAccount& acc1 = *accounts[index1];
                    BankAccount& acc2 = *accounts[index2];

                    // Compares balance between 2 accounts
                    std::cout << "Comparison:\n";
                    if (acc1 == acc2) { // Checks if balance is equal
                        std::cout << "Accounts are equal.\n";
                    }
                    else {
                        std::cout << "Accounts are not equal.\n";
                    }
                    if (acc1 < acc2) { // Checks if account 1 is less than account 2
                        std::cout << "First account has a lesser balance than the second.\n";
                    }
                    else if (acc1 > acc2) { // Checks if account 1 is greater than account 2
                        std::cout << "First account has a greater balance than the second.\n";
                    }
                    else {
                        std::cout << "Both accounts have the same balance.\n";
                    }
                    break;
                }

                case 6: {
                    if (accounts.empty()) {
                        std::cout << "No Account found." << std::endl;
                        break;
                    }
                    std::cout << "Accounts:\n";
                    for (i = 0; i < static_cast<int>(accounts.size()); ++i) {
                        std::cout << (i + 1) << ".\n";
                        BankAccount::printAccount(*accounts[i]);
                        std::cout << std::endl;
                    }
                    while (true) {
                        std::cout << "Choose account to view history: ";
                        std::cin >> index;
                        if (std::cin.fail() || index < 1 || index > static_cast<int>(accounts.size())) {
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::cout << "Invalid account. Try again.\n";
                        }
                        else {
                            index -= 1;
                            break;
                        }
                    }

                    accounts[index]->printHistory();
                    break;
                }

            case 7: // Choice 6 to quit program
                std::cout << "Quit\n";
                break;

            default: // Checks invalid choice
                std::cout << "Invalid input.\n";
        }
    }
    while (choice != 7);
}