#include <string>
#include <iostream>
#include "BankAccount.h"

using std::string;
using std::cout;
using std::endl;

// Constructor with parameters
BankAccount::BankAccount(string n, float b) : name(n), balance(b) {
    cout << "BankAccount constructor for: " << name << ", Balance: " << balance << endl;
}

// Function definitions
std::string BankAccount::get_name() {
    return name;
}

float BankAccount::get_balance(){
    return balance;
}
