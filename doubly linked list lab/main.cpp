#include <iostream>
#include "IntList.h"
//collaberation with  justin lyu jlyu015
using namespace std;

int main() {
    cout << "THIS IS MAIN" << endl;
    IntList list;

    cout << "TESTING EMPTY()" << endl;
    if(list.empty()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    cout << "TESTING PUSHFRONT" << endl;
    list.push_front(0);
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    cout << "DONE TESTING PUSHFRONT" << endl;
    cout << list << endl;


    cout << "Testing PUSHBACK" << endl; 
    list.push_back(99);
    list.push_back(100);
    cout << list << endl;

    list.printReverse();

    cout << "Finished testing";
}