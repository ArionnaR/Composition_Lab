// Arionna Rogers
// 10/6/25
// Extend program to log every deposit and withdrawal
// Lab Activities: Inheritance & Composition

#ifndef COMPOSITION_LAB_TRANSACTION_H
#define COMPOSITION_LAB_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(const std::string& type, double amount, const std::string& timestamp); // Constructor

    // Accessor methods
    std::string GetType() const;
    double GetAmount() const;
    std::string GetTimestamp() const;

private:
    std::string type;
    double amount;
    std::string timestamp;
};


#endif //COMPOSITION_LAB_TRANSACTION_H