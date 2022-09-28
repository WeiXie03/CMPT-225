#include <iostream>
#include <string>
#include "Deque.h"
using namespace std;

template <typename Object>
// if test passed, returns true; else, false
bool test_case(Deque<Object>& dq, int ind, int expec) {
    try {
        cout << "DQ["<< to_string(ind) <<"] = " << dq[ind] <<'\n';
        return (dq[ind] == expec);
    }
    catch (const char* err) { 
        cout << err << '\n';
        return false;
    }
}

void test_arr_access() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    cout << "Deque DQ, "; dq.display();
    cout <<'\n';

    int sample[] = {0, 3, 6, 9};
    for (int i : sample) {
        test_case(dq, i, i);
    }
    test_case(dq, 10, -1);
    test_case(dq, -1, -1);
}

int main() {
    test_arr_access();
}
