#pragma once
#include "Cricketer.h"

class Batsman : public Cricketer {
    private:
        int number_of_runs; 
        int number_of_centuries; 
    public: 
        int get_runs () const;
        void set_runs (int r);
        int get_centuries () const;
        void set_centuries (int c);
};