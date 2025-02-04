#pragma once
#include <string>

class Student { 
    public: 
        std::string name; 
        float gpa; 
        Student () = default ;
        std::string get_name () const; 
        float get_gpa() const; 
};