#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

template <typename Object>
class Deque 
{
  public:
    Deque()
      {  
         theCapacity = 8 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         front = 0 ; 
         back = 0 ; 
      }
      
    ~Deque( )
      { delete [ ] objects; }

    bool empty() const  { return size() == 0; }
    int size() const { return theSize; }
    Object& operator[] (int index);

    void clear(){
        // remove all contents and reset the capacity to it's initial value 
        // TODO: can I just destruct and re-refer `this` to a new one?
        delete[] objects;
        theSize = 0;
        theCapacity = 8;
        objects = new Object[ theCapacity ];
    }

    void reserve( int newCapacity )
    {
        // change the capacity to newCapacity 
        // (provided it is larger than the current size)
        if (newCapacity > theCapacity)
        {
            // first copy out to larger array
            Object* newarr = new Object[ newCapacity ];
            int i;
            for (int cur=0; cur < theSize; ++cur) {
                i = (front + cur) % theCapacity;
                // start everything at ind 0
                newarr[cur] = objects[i];
            }
            front = 0;
            back = theSize;
            // then delete old
            delete[] objects;
            objects = newarr;
            theCapacity = newCapacity;
        }
    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        //cout << "Inserting " << x <<'\n';
        //cout << "\tcurrent back = " << objects[back] <<", @ ind "<< back <<'\n';

        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ; 

        //cout << "\tnow back = " << objects[back] <<'\n';

        back = (back+1) % theCapacity ;

        //cout << "New back ind = " << back <<'\n';

        ++theSize;
    }

    void jump( const Object & x )// Insert a new object at the front 
    {
        // push everything back
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        // starting from back, "pull" each element one farther right/back
        int i;
        for (int cur = theSize; cur >= 0; --cur) {
            i = (front + cur) % theCapacity;
            // move back by 1
            objects[ (i+1) % theCapacity ] = objects[i];
        }
        objects[front] = x;
        ++theSize;
        back = (front + theSize) % theCapacity;
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        --theSize;
        Object temp = objects[front];
        front = (front+1) % theCapacity ;
        return temp ;
    }

    Object eject( )// Remove and return the object at the back 
    {
        if (empty()) {
            cout << "Error[eject()]: already empty";
            return -1;
        };
        --theSize;
        return objects[back];
    }

    // TODO: base off theSize
    void display() const // print out the contents of the deque
    {
        cout << "size=" << theSize << std::endl;
        
        //cout << "front ind="<< front <<", "<< "back ind="<< back <<'\n';
        cout << "< " ;
        int i;
        for (int cur=0; cur < theSize; ++cur) {
            i = (front + cur) % theCapacity;
            cout << objects[i] << ", " ;
        }
        cout << " >" << endl;
    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        // Implement this.  The output should be in the style used in 
        // Vector and Stack classes provided.
        cout << "capacity= " << theCapacity << ", size=" << theSize << std::endl;
        cout << "[ " ;
        int i;
        for (int cur=0; cur < theCapacity; ++cur) {
            i = (front + cur) % theCapacity;
            cout << cur << "=" << objects[i] << ", " ;
        }
        cout << " ]" << endl;
    }

  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

template<typename Object>
inline Object& Deque<Object>::operator[] (int index) {
    if (index < 0 || index >= theSize)
        throw ("Deque::operator[]: index out of bounds.\n");
    else {
        int arr_i = (front + index) % theCapacity;
        return objects[arr_i];
    }
}

/*
    int& operator[] (int index) {
    }
*/

#endif
