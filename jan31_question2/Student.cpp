#include "Student.h"
#include <string> 

std::string get_name () const { 
    return name;
}
void set_name (std::string n) {
    name = n;
}
int get_roll () const { 
    return roll;
}
void set_roll (int x) {
    roll = x;
}