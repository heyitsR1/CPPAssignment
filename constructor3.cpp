#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Student{
private: 
    string name;
    int clas;
    int roll;
    float marks;
public: 
    Student (string n, int c, int r, float m) {
        this ->name = n;
        this ->clas = c;
        this ->roll = r;
        this ->marks = m;
    }

    float calculateGrade(){
        if (marks >= 90 ) {
            return 4;
        } else if (marks < 90 && marks >= 75) {
            return 3.5;
        } else if (marks < 75 && marks >= 50) {
            return 3.0;
        } else if (marks < 50 && marks >= 30) {
            return 2.5;
        } else if (marks < 30 && marks >= 20) {
            return 2.0;
        } else {
            return 0;
        }
    }
    void getStudentInfo() {
        cout << "Student Name is " << name << ", Class : " << clas << ", Roll: " << roll << ", Marks : " << marks <<endl;
    }  
};
int main () {

    string n;
    int c,r;
    float m;

    cout << "Enter name : ";
    cin >> n;
    cout << "Enter class : ";
    cin >> c;
    cout << "Enter roll: ";
    cin >> r;
    cout << "Enter marks : ";
    cin >> m;
    Student student1(n,c,r,m);
    student1.getStudentInfo();
    cout << "Grade is " << student1.calculateGrade() <<endl;
}