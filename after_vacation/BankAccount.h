#pragma once
#include <string> 

class BankAccount { 
    private: 
        std::string name;  // Removed in-class initialization
        float balance;     // Removed in-class initialization

    public: 
        BankAccount() : name(""), balance(0) {}  // Default constructor initializing members
        BankAccount(std::string n, float b);     // Parameterized constructor
        std::string get_name();            // Function to return name
        float get_balance();               // Function to return balance
};
