#include "Topic.h"
#include "Message.h"
Topic::Topic() {
    
}
    
    //Parameterized constructor
Topic::Topic(const string &athr, const string &sbjct, const string &body, unsigned id) : Message(athr, sbjct, body, id) {
}

bool Topic::isReply() const {
    return false;
    } // Returns false
      
    /* to_formatted_string writes the contents of the Topic to a
    * string in the following format:
    
    <begin_topic>
    :id: 4
    :subject: single line
    :from: author
    :children: 5 6 [this line should not be printed if there are no children.]
    :body: multiple lines - line 1
    line 2
    line 3
    <end>
    
    * line starting with :children: has the id's of all children
    * (See file specifcations for details)
    * This function should not assume the last character in body is a newline.
    * In other words, this function must manually add a newline after the last
    * line of the body (line 3 in the above example).
    * Also, the last character in the string must be a newline.
    */
string Topic::toFormattedString() const {
    string topicString;
    
    topicString = "<begin_topic>\n";
    topicString = topicString + Message::toFormattedString();
    return topicString;
    }
