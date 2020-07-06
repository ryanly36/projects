#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct personNode {
    string name;
    personNode *next = nullptr;
    personNode *prev = nullptr;
    personNode(string name): name(name), next(0), prev(0){}
};

class PersonList {
    public:
        PersonList();
        ~PersonList();
        void remove();
        void push_back(string name);
        void remove(int n);
        friend ostream & operator <<(ostream &out, const PersonList &rhs);
        personNode* play(int n, int k, int skip);
    private:
        personNode *head;
};
PersonList::PersonList() {
    head = nullptr;

}
PersonList::~PersonList() {

}
void PersonList::push_back(string username) {
    personNode* temp;
    temp = new personNode(username);

    if(head == nullptr) {
        head = temp;
        head->next = temp;
        head->prev = temp;
    }
    else {
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        temp->next = head;
    }
}
ostream & operator<<(ostream &out, const PersonList &rhs) {
    personNode *curr = nullptr;
    curr = rhs.head;
    if(curr == nullptr) {
        
    }
    else {
        while(curr->next != rhs.head) {
        out << curr->name << ' ';
        curr = curr->next;
        }
        out << curr->name;
    }
    return out;
}

personNode* PersonList::play(int n, int k , int skip) {
    personNode *currPerson = head;

    //starter position
    for(unsigned i = 0; i <= k -1; ++i) {
        currPerson = currPerson->next;
    }

    while(currPerson->next != currPerson) {
        for(unsigned z = 0; z < skip-1; ++z) {
            currPerson = currPerson->next;
        }
        cout << currPerson->name << " dies" <<endl;
        personNode *temp = currPerson;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        currPerson = currPerson->next;

    }

    return currPerson;
}
int main(int argc, char *argv[]) {
    ifstream inFS;
    string currName;
    PersonList list;
    int n = 0;
    int k;
    int skip;
    string inputFile = argv[1];

    inFS.open(inputFile);
    if(!inFS.is_open()) {
        cout << "Error: could not open file. Exiting program" << endl;
        exit(1);
    }
    while(inFS >> currName) {
        list.push_back(currName);
        n++;
    }

    cout << "enter the number of people in the initial circle" << endl;
    cin >> n;
    cout << "enter the number of a person to start counting from" << endl;
    cin >> k;
    cout << "how many people to skip" << endl;
    cin >> skip;

    personNode * winner = list.play(n, k, skip);
    

    cout << "The last survivor is: " << winner->name << endl;



    return 0;
}