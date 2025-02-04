#pragma once
#include "Cricketer.h"

class Bowler : public Cricketer {
    private:
        int wicket; 
    public: 
        int get_wicket () const;
        void set_wicket (int w);
};