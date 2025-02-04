#include <iostream>
#include "BankAccount.h"

using std::cout;
using std::endl;

int main() {
    // Creating BankAccount objects
    BankAccount claudia_account("Claudia", 1000.55f);
    BankAccount peter_account("Peter", 5342.34f);
    BankAccount kira_account;  // Default constructor

    // Printing details for Claudia's account
    cout << "Claudia's account" << endl;
    cout << claudia_account.get_name() << endl;
    cout << claudia_account.get_balance() << endl;

    // Printing details for Peter's account
    cout << "Peter's account" << endl;
    cout << peter_account.get_name() << endl;
    cout << peter_account.get_balance() << endl;

    // Printing details for Kira's account (default values)
    cout << "Kira's account" << endl;
    cout << kira_account.get_name() << endl;
    cout << kira_account.get_balance() << endl;

    return 0;
}
