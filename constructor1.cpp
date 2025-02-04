#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Employee {
private: 
    string name;
    int id;
    float salary;
public: 
    Employee (string n, int id, float s) {
        this ->name = n;
        this ->id = id;
        this ->salary = s;
    }
    float calculateSalary(float effectiveness){
        if (effectiveness >= 0.7) {
            salary = (1.5*salary);
        } 
        return salary;
    }
    float getSalary() {
        return salary;
    }
};
int main () {
    float e;
    Employee Aarohan("r1",559,696.69);
    cout << "Enter effectiveness score for Aarohan: ";
    cin >> e;
    cout << "Revised Salary is " << Aarohan.calculateSalary(e) << endl;
    cout<< "Final Salary is " << Aarohan.getSalary();
}