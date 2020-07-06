#include "Heap.h"
#include <iostream>

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob *user) {
    if(numItems < MAX_HEAP_SIZE) {
        arr[numItems] = user;
        trickleUp(numItems);
        numItems++;
    }

}

void Heap::dequeue() {
    if(numItems == 1) {
        arr[0] = 0;
        numItems = 0;
        return;
    }
    if(numItems > 1) {
        arr[0] = arr[numItems - 1];
        arr[numItems-1] = 0;
        numItems--;
        trickleDown(0);
        return;
    }
}

PrintJob* Heap::highest() {
    return arr[0];
}

void Heap::print() {
    if(arr[0] != 0) {
        cout << "Priority: " << arr[0]->getPriority();
        cout << ", Job Number: " << arr[0]->getJobNumber();
        cout << ", Number of Pages: " << arr[0]->getPages();
        cout << endl;
    }
   
}

void Heap::trickleDown(int value) {
    for(int i = 0; i < numItems; ++i) {
        if(arr[value]->getPriority() < arr[i]->getPriority()) {
            swap(value, i);
        }
    }
}

void Heap::trickleUp(int value) {
    while(value >= 1 && arr[value]->getPriority() > arr[(value-2)/2]->getPriority()) {
         swap(value, (value-1)/2);
         value = (value-1)/2;
    }
}


void Heap::swap(int x, int y) {
    PrintJob* temp;
    temp = arr[y];
    arr[y] = arr[x];
    arr[x] = temp;

}