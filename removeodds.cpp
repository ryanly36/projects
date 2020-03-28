#include "IntList.h"

void IntList::removeOdds() {
   if(head!= nullptr) {
      IntNode* node = head;
      while(node->data % 2 != 0) { // it's odd
         IntNode* temp = head;
         if(node->next != nullptr) {
            node = node->next;
            delete temp;
            head = node;
         } //inner if statement
         else if (node->next == nullptr){
            delete node;
            head = nullptr;
         } // inner else 
         
      } /// while loop
      while(node->next != nullptr) {
         if(node->next->data % 2 != 0) {
            IntNode* temp = node->next;
            node->next = node->next->next;
            delete temp;
         } // second inner if
         else if (node->next->data % 2 == 0){
            node = node->next;
         } // second inner else
         
      } // second while
      
      
      
   } // main if statement
    
} // function