#include "IntList.h"
//collaberation with  justin lyu jlyu015
    IntList::IntList() {
        dummyHead = new IntNode(0); // dummy nodes are made to avoid additional codes for edge cases
        dummyTail = new IntNode(0);
    }
    IntList::~IntList() {
        while(dummyHead->next != nullptr) {
            IntNode* temp;
            temp = dummyHead->next;
            dummyHead->next = dummyHead->next->next;
            delete temp;
        }
    }
    void IntList::push_front(int value) {
        IntNode* temp;
        temp = new IntNode(value); // take in new value

        if(empty()) {
            dummyHead->next = temp;
            temp->prev = dummyHead;
            temp->next = dummyTail;
            dummyTail->prev = temp;
        }
        else {
            temp->next = dummyHead->next;
            dummyHead->next = temp;
            dummyHead->next->next->prev = temp;
            temp->prev = dummyHead;
        }
    }
    void IntList::pop_front() {
        if(dummyHead->next != nullptr) {
            if(dummyHead->next->next != dummyTail) {
                IntNode* temp;
                temp = dummyHead->next;
                dummyHead->next = dummyHead->next->next;
                dummyHead->next->prev = dummyHead;
                delete temp;
            }
            else {
                IntNode* temp;
                temp = dummyHead->next;
                dummyHead->next = nullptr;
                dummyTail->prev = nullptr;
                delete temp;
            }
        }
       
    }
    void IntList::push_back(int value) {
        IntNode* temp;
        temp = new IntNode(value);

        if(empty()) {
            dummyTail->prev = temp;
            temp->next = dummyTail;
            temp->prev = dummyHead;
            dummyHead->next = temp;
        }
        else {
            temp->prev = dummyTail->prev;
            dummyTail->prev = temp;
            dummyTail->prev->prev->next = temp;
            temp->next = dummyTail;
        }
        

    }
    void IntList::pop_back() {
        if(dummyTail->prev != nullptr) {
            if(dummyTail->prev->prev != dummyHead) {
                IntNode* temp;
                temp = dummyTail->prev;
                dummyTail->prev = dummyTail->prev->prev;
                dummyTail->prev->next = dummyTail;
                delete temp;
            }
            else {
                IntNode* temp;
                temp = dummyTail->prev;
                dummyHead->next = nullptr;
                dummyTail->prev = nullptr;
                delete temp;
            }
        }
        
    }
    bool IntList::empty() const {
        if(dummyHead->next == nullptr) {
            return true;
        }
        else {
            return false;
        }

    }
    void IntList::printReverse() const {
        IntNode* temp;
        temp = dummyTail;
        
        if(empty()) {
            cout << "";
        }
        else {
            temp = temp->prev;
            while(temp->prev != dummyHead) {
                cout << temp->data << " ";
                temp = temp->prev;
        }
        cout << temp->data;
        }
    }
    
    ostream & operator <<(ostream &out, const IntList &rhs) {
        IntNode* curr;
        curr = nullptr;
        curr = rhs.dummyHead;

        if(rhs.empty()) {
            cout << "";
        }
        else {
            curr = curr->next;
            while(curr->next != rhs.dummyTail) {
                out << curr->data << " ";
                curr = curr->next;
            }
            out << curr->data;
        }

        return out;
    }