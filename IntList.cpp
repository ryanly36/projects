#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

/* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
*/
ostream & operator<<(ostream & out, const IntList &list) {
    out << list.head;
    return out;
}

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream & operator<<(ostream & out, IntNode *node) {
    if(node != nullptr) {
        out << node->data;
        if(node->next != nullptr) {
            out << " ";
        }
        out << node->next;
    }
    return out;
}
   /* Returns true if the integer passed in is contained within the IntList.
      Otherwise returns false.
   */
bool IntList::exists(int val) const {
   return exists(head, val);    
   }
   /* Helper function that returns true if the integer passed in is contained within
      the IntNodes starting from the IntNode whose address is passed in.
      Otherwise returns false.
   */
bool IntList::exists(IntNode *curr, int val) const {
    if(curr != nullptr) {
        if(curr->data == val) {
            return true;
        }
        return exists(curr->next, val);
    }
    return false;
}



