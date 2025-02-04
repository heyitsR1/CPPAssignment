
#pragma once
#include <string>
using std::string;

class Cricketer { 
    private: 
        std::string name;
        int age;
        int matches;
    
    public: 
        string get_name () const;
        void set_name (string n);

        int get_age () const;
        void set_age (int a);

        int get_matches () const;
        void set_matches(int m);

};