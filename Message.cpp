#include "Message.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
Message::Message() {
    
}
    
    // Parameterized constructor;
    // id will be the size of current BBoard's message_list
Message::Message(const string &athr, const string &sbjct, const string &body, unsigned id) {
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
    }

    // Be very careful here: some Messages will have two pointers to
    // them, stored in very different places!
    // Where are they, and who should be responsible for deleting
Message::~Message() {
    for(unsigned i = 0; i < childList.size(); ++i) {
        delete childList.at(i);
    }
}
    
    
string Message::toFormattedString() const {
    string string;
    stringstream stri;
    

    stri << ":id: " << id << "\n";
    stri << ":subject: " << subject << "\n";
    stri << ":from: " << author << "\n";
    if(childList.size() != 0) {
        stri << ":children: ";
        for(unsigned i = 0; i < childList.size(); i++) {
            stri << (childList.at(i))->getID();
            if(i != childList.size()-1) {
                stri << " ";
            }
        }
        stri << "\n";
    }
    stri << ":body: " << body << "\n";
    stri << "<end>\n";
    string = stri.str();
    return string;
    
}
        
//     } // New!!
    
    /* This function is responsible for printing the Message
    * (whether Topic or Reply), and and all of the Message's
    * "subtree" recursively:
    * After printing the Message with indentation n and appropriate
    * format (see output details), it will invoke itself
    * recursively on all of the Replies in its child_list,
    * incrementing the indentation value at each new level.
    *
    * Note: Each indentation increment represents 2 spaces. e.g. if
    * indentation == 1, the reply should be indented 2 spaces, if
    * it's 2, indent by 4 spaces, etc.
    */
void Message::print(unsigned indentation) const {
    string s, bod;
    bod = body;
    
    for(unsigned i = 0; i < indentation; i++) {
        s = s + "  ";
    }
    if(indentation != 0) {
        cout << endl;
    }
    
    if(subject.at(0) != ' ') {
        cout << s << "Message #" << id << ": " << subject << endl;
        cout << s << "from " << author << ": ";
    }
    else {
        cout << s << "Message #" << id << ":" << subject << endl;
        cout << s << "from " << author << ":";
    }
    
    for(unsigned i = 0; i < bod.size(); i++) {
        if(bod.at(bod.size()-1) == '\n') {
            bod.erase(bod.size() -1);
        }
        if(bod.at(0) == ' ') {
            bod.erase(bod.at(0));
        }
        cout << bod.at(i);
        if(bod.at(i) == '\n') {
            cout << s;
        }
    }
    cout << endl;
    if(childList.size() != 0) {
        for(unsigned i = 0; i < childList.size(); i++) {
            childList.at(i)->print(indentation+1);
        }
    }
 }
    
    //returns the subject string.
const string & Message::getSubject() const {
        return subject;
    }
    
    // returns the id.
unsigned Message::getID() const {
    return id;
        
    }// New !!
    
    // Adds a pointer to the child to the parent's child_list.
void Message::addChild(Message *childMes) {
    childList.push_back(childMes);
    }
