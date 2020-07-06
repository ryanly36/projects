#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>
using namespace std;
//collab with justin lyu jlyu015

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    T min = vals.at(index);
    unsigned minIndex;
    for(unsigned i = index; i < vals.size();++i) {
        if(vals.at(i) < min) {
            min = vals.at(i);
        }
    }
    for(unsigned i = index; i < vals.size(); ++i) {
        if(vals.at(i) == min) {
            minIndex = i;
            break;
        }
    }
    
      return minIndex;;
}

template<typename T>
void selection_sort(vector<T> &vals){
    T temp;
    unsigned min; 
    for(unsigned i = 0; i < vals.size(); ++i) {
        min = min_index(vals, i);
        temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
    }
}

template<typename T>
T getElement(vector<T> vals, int index) {
    return vals.at(index);
}

template<typename T>
void display(const vector<T> &vals) {
    for(unsigned i = 0; i < vals.size(); ++i) {
        cout << vals.at(i) << endl;
    }
}


vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main( ){
    vector<string> list3;
    list3.push_back("d");
    list3.push_back("a");
    list3.push_back("c");
    list3.push_back("y");
    list3.push_back("q");
    list3.push_back("y");
    list3.push_back("t");
    display(list3);
    cout << endl;
    selection_sort(list3);
    display(list3);

     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         try {
            if(index < 0 || index > 25) {
               throw 99;
            }
         }
            catch(int x) {
                cout << "out of range exception occured" << endl;
                cout << "Enter a number: " << endl;
                cin >> index;
         }
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
     }
    return 0;
}


