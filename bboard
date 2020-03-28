#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

#include "BBoard.h"
#include "Topic.h"
#include "Reply.h"

BBoard::BBoard() {
    title = "";
    current_user = nullptr;
}

BBoard::BBoard(const string &tit) {
    title = tit;
    current_user = nullptr;
}

bool BBoard::loadUsers(const string &filename) {
     ifstream fin;
     string userNew, passNew;
     fin.open(filename);
    
     if(!fin.is_open()) {
          return false;
     }
    while(fin >> userNew >> passNew) {
        User currentUser(userNew, passNew);
        user_list.push_back(currentUser);
     }
    fin.close();
    return true;
    }

void BBoard::login() {
string user, pass;
   cout << "Welcome to " << title << endl;
   while(true){
       cout<< "Enter your username (\'Q\' or \'q\' to quit): ";
       cin >> user;
       if(user == "q" || user == "Q"){
           cout << "Bye!" << endl;
           return;
       }
       cout<<"Enter your password: ";
       cin >> pass;
       
       current_user = getUser(user, pass);
       if(current_user) {
           cout << endl << "Welcome back " << current_user->getUsername() << '!' << endl << endl;
           break;
       }
       cout<< "Invalid Username or Password!" << endl << endl;
   }
//     string user, pass;
//     cout << "Welcome to Ryan's Bulletin Board" << endl;
//     cout << "Enter your username ('Q' or 'q' to quit): ";
//     cin >> user;
//     cout << endl;
//     if(user == "q" || user == "Q") {
//         cout << "Bye!" << endl;
//         exit(0);
//     }
//     if(user != "q" || user != "Q") {
//         cout << "Enter your password: ";
//         cin >> pass;
//         cout << endl;
//     }
    
//     for(unsigned i = 0; i < user_list.size(); ++i) {
//         if((user == user_list.at(i).getUsername()) && (pass == user_list.at(i).getPassword())) {
//             current_user = &user_list.at(i);
//             cout << "Welcome back " << current_user->getUsername() << '!' << endl;
//             return;
//             }
//         else {
//             cout << "Invalid Username or Password!" << endl;
//             cout << endl << "Enter your username ('Q' or 'q' to quit): ";
//             cin >> user;
//             cout << endl;
//             if(user == "q" || user == "Q") {
//                 cout << "Bye!" << endl;
//                 exit(0);
//         }
//             cout << "Enter your password: ";
//             cin >> pass;
//             cout << endl;
//         }
//     }
    
 }


void BBoard::run() {
   char userInput = 's';
    
   if(current_user == nullptr) {
       return;
   }
   while((userInput != 'Q') && (userInput != 'q')) {
       cout << "Menu" << endl;
       cout << "- Display Messages ('D' or 'd')" << endl;
       cout << "- Add New Topic ('N' or 'n')" << endl;
       cout << "- Add Reply to a Topic ('R' or 'r')" << endl;
       cout << "- Quit ('Q' or 'q')" << endl;
       cout << "Choose an action: ";
       cin >> userInput;
       
       if((userInput == 'Q') || (userInput == 'q')) {
           cout << "Bye!" << endl;
           return;
       }
       if((userInput == 'N') || (userInput == 'n')) {
           addTopic();
       }
       if((userInput == 'R') || (userInput == 'r')) {
           addReply();
       }
       if((userInput == 'D') || (userInput == 'd')) {
            cout << endl;
           display();
       }
   }
}

BBoard::~BBoard() {
    delete current_user;
    for(unsigned i = 0; i < message_list.size(); ++i) {
        if(message_list.at(i)) {
            delete message_list.at(i);
        }
}
}

bool BBoard::loadMessages(const string &datafile) {
        ifstream fin;
        int childID;
        string discard, author, subject, children, body, header, curr;
        unsigned numMes;
        int count = 0;
        unsigned id;
        vector<unsigned> child_list;
        
 


        fin.open(datafile);

        if(!fin.is_open()) {
            return false;
        }

        else {
            fin >> numMes;
            if(numMes > 0) {
                for (unsigned i = 0; i < numMes; ++i) {
                    fin >> header;
    
                body = "";
                children = "empty";
                fin >> discard;
//                 cout << "discard" //check what it takes in
                fin >> id;
                fin >> discard;
                getline(fin, subject);
                subject.erase(0, 1);
                fin >> discard;
                fin>> author;
                fin >> discard;
                if(discard == ":children:") {
                    getline(fin, children);
                    stringstream ss(children);
                    if(children.size() >= 2) {
                        int temp;
                        while (ss >> temp) {
                            childID = temp;
                            child_list.push_back(childID);
                    
            }
    }
                    fin >> discard;
                      
                    }

                if (discard == ":body:") {
                  string tempString;
                  fin.ignore();
                  getline(fin,curr);
                  body += curr;

                while(tempString != "<end>") {
                  getline(fin, tempString);
                  if(tempString != "<end>") {
                  body = body + "\n" + tempString;
                            }
                        }
                    }
            if (header == "<begin_topic>") {

            Topic* currT = new Topic(author, subject, body, id);
            message_list.push_back(currT);
    }
                    else if(header == "<begin_reply>") {

                    Reply* currR = new Reply(author, subject, body, id);
                    message_list.push_back(currR);
                    }
                     child_list.push_back(0);

                }
                 for(unsigned i = 0; i < child_list.size() - 1; ++i) {
                if(child_list.at(i) != 0){
                    (message_list.at(count))->addChild(message_list.at(child_list.at(i) - 1));
                }
                else
                    if(child_list.at(i) == 0 && child_list.at(i + 1) != 0) {
                        ++count;
                    }

                }
            }
        
//             cout << endl;
//                 cout << header << endl;
//                 cout << ":id: " << id << endl;
//                 cout << ":subject:" << subject << endl;
//                 cout << ":from: " << author << endl;
//                 cout << ":body:" << body << endl;
        fin.close();
        return true;
        }
    }


bool BBoard::saveMessages(const string &datafile) {
    ofstream fout;
    
    fout.open(datafile.c_str());
    if(fout.is_open()) {
        fout << message_list.size() << "\n";
        for(unsigned i = 0; i < message_list.size(); ++i) {
            fout << message_list[i]->toFormattedString();
        }
        fout.close();
        return true;
    }
    
    return false;
   
}

void BBoard::display() const {
   if(message_list.empty()) {
       cout << "Nothing to Display." << endl << endl;
   }
   else {
       for(unsigned i = 0; i < message_list.size(); ++i) {
           if(!message_list.at(i)->isReply()) {
               cout << "---------------------------------------------------------" << endl;
               message_list.at(i)->print(0);
           }
       }
               cout << "---------------------------------------------------------" << endl << endl;
           }
       }
  
//     if(messageList.size() == 0) {
//         cout << endl << "Nothing to Display." << endl;
//     }
//     else {
//         cout << endl << "---------------------------------------------------------" << endl;
//         for(unsigned i = 0; i < messageList.size(); ++i) {
//             cout << "Message #" << i+1 << ": ";
//             messageList.at(i).display();
//             cout << endl << "---------------------------------------------------------";
//             cout << endl;
//         }
//     }
// }

// void BBoard::addUser(const string &name, const string &pass) {
    
// }
const User* BBoard::getUser(const string &name, const string &pw) const {
    for(unsigned i = 0; i < user_list.size(); ++i) {
        if(user_list.at(i).check(name,pw) == true) {
            return &user_list.at(i);
        }
     
    }
    return nullptr;
}

void BBoard::addTopic() {
    string userInput, subject = " ", body, bodyInput, wow;
    int id;
    Message *addTopic = nullptr;
    id = message_list.size() +1;
    
    cin.ignore();
    cout << "Enter Subject: ";
    getline(cin, wow);
    subject = subject + wow;
    id = message_list.size() + 1;
    cout << "Enter Body: ";
    cout << endl;
    
    
    getline(cin, bodyInput);
    body = body + " " + bodyInput;
    while (bodyInput != "") {
        getline(cin, bodyInput);
        if(bodyInput == "") {
            break;
        }
        body = body + "\n" + bodyInput;
    }
    

        addTopic = new Topic(current_user->getUsername(), subject, body, id);
        message_list.push_back(addTopic);
    }
//    string subject, body, tmp;
//    int id;
//    id = message_list.size() + 1;
//    cout << "Enter Topic: ";
//    getline(cin, subject);
//    if(subject == "") {
//    cout << "Enter Body: ";
//    getline( cin, tmp);
//    }
//    if( tmp == "" )
//        getline( cin, tmp);
//    while ( tmp != "" ){
//        body = body + '\n' + tmp;
//        getline( cin, tmp );
//    }
//    body.erase( 0, 1 ); //remove the first character '\n'
//    Message *mg = new Topic( current_user->getUsername(), subject, body, id );
//    message_list.push_back( mg );

void BBoard::addReply() {
    string body, temp, subject, body2;
    int messageID;
    unsigned id;
    Reply *addReply = nullptr;
    
    id = message_list.size() + 1;
    
    cout << "Enter Message ID (-1 for Menu): ";
    cin >> messageID;
    
    while(messageID != -1 && (messageID < 1 || static_cast<unsigned>(messageID) > message_list.size())) {
       
            cout << "Invalid message ID!!" << endl << endl;
            cout << "Enter Message ID (-1 for Menu)";
            cin >> messageID;
    }
    if(messageID == -1) {
        return;
        
    }
    subject = "Re: " + message_list.at(messageID-1)->getSubject();
    cout << "Enter Body: ";
    cin.ignore();
        
    getline(cin, body2);
    body = body + body2;
//         if(body == "") {
//             return;
//         }
        while(body2 != "") {
            getline(cin, body2);
            body = body + "\n" + body2;
            
        }
    
        addReply = new Reply(current_user->getUsername(), subject, body, id);
        message_list.push_back(addReply);
        message_list.at(messageID - 1) -> addChild(addReply);
        
    
        
    
    return;
}
