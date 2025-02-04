#include <iostream>
#include "Cricketer.h"
#include "Bowler.h"
#include "Batsman.h"
using std::cout, std::endl;

int main () {
    Cricketer GuyA; 
    Bowler GuyB; 
    Batsman GuyC;

    GuyA.set_name ("Aarohan");
    GuyA.set_age(19);
    GuyA.set_matches(5);
    cout<<GuyA.get_name()<<endl;

    GuyB.set_name ("Rohan");
    GuyB.set_age(29);
    GuyB.set_matches(51);
    GuyB.set_wicket(500);
    cout<<GuyB.get_name()<< " has " << GuyB.get_wicket() << " wickets"<<endl;

    GuyC.set_name ("Han");
    GuyC.set_age(39);
    GuyC.set_matches(225);
    GuyC.set_runs(25000);
    GuyC.set_centuries(45);
    cout<<GuyC.get_name()<< " is " << GuyC.get_age() << " has played "<< GuyC.get_matches() << " matches" << " and has " << GuyC.get_runs()<< " runs!" <<endl;

    
};