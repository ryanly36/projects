#include <iostream>
#include <string>
using namespace std;

#include "User.h"

// creates a user with empty name and password.
User::User() {
    username = "";
    password = "";
}

  // creates a user with given username and password.
User::User(const string& uname, const string& pass) {
    username = uname;
    password = pass;
}

  // returns the username
string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

  /* returns true if the stored username/password matches with the
   * parameters. Otherwise returns false.
   * Note that, even though a User with empty name and password is
   * actually a valid User object (it is the default User), this
   * function must still return false if given a empty uname string.
   */
bool User::check(const string &uname, const string &pass) const {
    if(username == uname && password == pass) {
        if(username.size()!= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

  /* sets a new password.
   * This function should only set the new password if the current (old)
   * password is passed in. Also, a default User cannot have its
   * password changed.
   * returns true if password changed, false if not.
   fix me
   */
bool User::setPassword(const string &oldpass, const string &newpass) {
    bool check;
    if(oldpass == password) {
        if(password.size() != 0) {
            password = newpass;
            check = true;
        }
        else {
            check = false;
        }
    }
    return check;
}
    
