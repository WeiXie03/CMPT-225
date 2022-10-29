#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
    const int n_ele = 6;
    int keys[] = {8,3,9,1,4,13};

    cout << "Start of Dtest" << endl;

    for(int i = 0; i < n_ele; i++) {
        t.insert( keys[i] );
    }

    if( n_ele < 40 )
    {
        cout << "Keys:" << endl ;
        t.printTree( );
        cout << "Tree:" << endl ;
        t.displayTree(); 

        cout << "====Program Output====" << endl;
        cout << "Links:" << endl ;
        t.displayLinks(); 
        
        cout << endl << "====Expected: ====" << endl;
        cout << "8) @:&8 L:&3 R:&9" << endl;
        cout << '\t' << "3) @:&3 L:&1 R:&4" << endl;
        cout << "\t\t" << "1) @:&1 L:0 R:0" << endl;
        cout << "\t\t" << "4) @:&4 L:0 R:0" << endl;
        cout << '\t' << "9) @:&9 L:0 R:&13" << endl;
        cout << "\t\t" << "13) @:&13 L:0 R:0" << endl;
    }

/*
    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );

    if( NUMS < 40 ) t.printTree( );

    BinarySearchTree<int> t2;
    t2 = t;
*/
    cout << "End of Dtest" << endl;

    return 0;
}
