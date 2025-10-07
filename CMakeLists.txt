cmake_minimum_required(VERSION 4.0)
project(Composition_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Composition_Lab main.cpp
        BankAccount.cpp
        BankAccount.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h
        Transaction.cpp
        Transaction.h)
