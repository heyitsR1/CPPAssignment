#include "Cricketer.h"
#include "Batsman.h"

    int Batsman::get_runs () const{
        return number_of_runs;
    }
    void Batsman::set_runs (int r) {
        number_of_runs = r;
    }
    int Batsman::get_centuries () const{
        return number_of_centuries;
    }
    void Batsman::set_centuries (int c) {
        number_of_centuries = c;
    }


