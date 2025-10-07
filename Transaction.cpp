// Arionna Rogers
// 10/6/25
// Extend program to log every deposit and withdrawal
// Lab Activities: Inheritance & Composition

#include "Transaction.h"

// Constructor
Transaction::Transaction(const std::string& type, double amount, const std::string& timestamp) : type(type), amount(amount), timestamp(timestamp) {}

std::string Transaction::GetType() const { // Getter for type
    return type;
}

double Transaction::GetAmount() const { // Getter for amount
    return amount;
}

std::string Transaction::GetTimestamp() const { // Getter for timestamp
    return timestamp;
}
