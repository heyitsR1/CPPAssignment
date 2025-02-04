#include <iostream>
using namespace std; 

class Counter {
    private:
        int count_for_object;
        static inline unsigned int TotalCount = 0;

    public:
        Counter (int c = 0) {
            TotalCount++;
            count_for_object = c;
        }
        int increase_object_count(int x=1){ //by default increases by one if function called.
            count_for_object +=x; 
        }
        int get_object_count (){
            return count_for_object;
        }
        static int get_TotalCount(){
            return TotalCount;
        }

};

int main () {
    Counter obj1(3);
    Counter obj2(5);
    Counter obj3(0);

    cout << "Count for each object is " <<endl;
    cout << "Count for object 1 is " << obj1.get_object_count() <<endl;
    cout << "Count for object 2 is " << obj2.get_object_count() <<endl;
    obj2.increase_object_count(3);
    cout << "Count for object 2 is " << obj2.get_object_count() <<endl;
    cout << "Count for object 3 is " << obj3.get_object_count() <<endl;

    cout << "Total Count is " << Counter::get_TotalCount() << endl;

}