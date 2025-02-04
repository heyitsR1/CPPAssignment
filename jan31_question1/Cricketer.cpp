#include <iostream>
#include <string>
#include "Cricketer.h"
using std::string;

    string Cricketer::get_name () const {
        return name;
    }

    void Cricketer::set_name (string n) {
        name = n;
    }
    int Cricketer::get_age () const{
        return age;
    }
    void Cricketer::set_age (int x) {
        age = x;
    }
    int Cricketer::get_matches () const{
        return matches;
    }
    void Cricketer::set_matches (int m) {
        matches = m;
    }

