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

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ){
        // remove all contents and reset the capacity to it's initial value 
        // 
        // Implement this...
    }

    void reserve( int newCapacity )
    {
        // change the capacity to newCapacity 
        // (provided it is larger than the current size)
        if (newCapacity <= theCapacity) return;

        // first copy out to larger array
        Object* newarr = new Object[ newCapacity ];
        // then delete old
        delete[] objects;
        objects = newarr;
    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        cout << "Inserting " << x <<'\n';
        cout << "\tcurrent back = " << objects[back] <<'\n';
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ; 
        cout << "\tnow back = " << objects[back] <<'\n';
        back = (back+1) % theCapacity ;
        cout << "New back ind = " << back <<'\n';
        theSize++ ;
    }

    void jump( const Object & x )// Insert a new object at the front 
    {
        // Implement this 
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        theSize--;
        Object temp = objects[front];
        front = (front+1) % theCapacity ;
        return temp ;
    }

    Object eject( )// Remove and return the object at the back 
    {
        // Implement this 
    }

    void display() const // print out the contents of the deque
    {
        cout << "size=" << theSize << std::endl;
        
        cout << "front ind="<< front <<", "<< "back ind="<< back <<'\n';
        cout << "< " ;
        // first forward to arr end
        for (int i = front; i < (theCapacity - front); ++i) {
           cout << i << "=" << objects[i] << ", " ;
        }
        // then wrap around to back
        for (int i= 0; i < back; ++i) {
           cout << i << "=" << objects[i] << ", " ;
        }
        cout << " >" << endl;
    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        // Implement this.  The output should be in the style used in 
        // Vector and Stack classes provided.
    }


  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
