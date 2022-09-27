#include <iostream>
#include "Deque.h"
using namespace std;

template <typename Object>
void Deque<Object>::reserve( int newCapacity ) {
    // change the capacity to newCapacity 
    // (provided it is larger than the current size)
    if (newCapacity <= theCapacity) return;

    // first copy out to larger array
    Object* newarr = new Object[ newCapacity ];
    // then delete old
    delete[] objects;
    objects = newarr;
}

template <typename Object>
void Deque<Object>::display() const {
   // Implement this.  The output should be similar to that 
   // used in the Vector and Stack classes provided.
    cout << "size=" << theSize << std::endl;

    cout << "< " ;
    int i = front;
    while (i != back)
    {
       cout << i << "=" << objects[i] << ", " ;
       i = (i+1) % theCapacity;
    }
    cout << " >" << endl;
}
