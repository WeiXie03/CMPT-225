#include <iostream>
#include "Deque.h"
using namespace std;

void test_enqueue_char() {
    cout << "==== enqueue() Test (char) ====\n";

    cout << "Expected resulting deque: <d, o, u, b, l, e,  , e, n, d, e, d, >, size == 12, capacity == 17\n";
    Deque<char> dq;
    string eles = "double ended";
    for (char c : eles) {
        dq.enqueue(c);
    }
    cout << "Actual(debug print): "; dq.ddisplay();
}
void test_enqueue_int() {
    cout << "==== enqueue() Test (int) ====\n";

    Deque<int> dq;
    cout << "Expected resulting deque: <0, 1, 2, 3, 4, 5, 6, 7, 8, 9, >, size == 10, capacity == 17\n";
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        //cout << "\tinserting " << i <<'\n';
        dq.enqueue(i);
    }
    cout << "Actual(debug print): "; dq.ddisplay();
}
void test_dequeue_int() {
    cout << "==== dequeue() Test ====\n";

    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    cout << "start: deque = "; dq.display();
    cout << "start dequeuing all elements, expected deque sequence is 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9\n";
    cout << "dequeued";
    for (int i : eles) {
        cout << " -> " << dq.dequeue();
    }
    cout << "\nnow "; dq.display(); cout << '\n';
}
void test_clear() {
    cout << "==== clear() Test ====\n";

    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    cout << "start: deque = "; dq.display();
    cout << "Expected result: <, >\n";
    cout << "clearing now\n";
    dq.clear();
    cout << "Actual: "; dq.display();
}
void test_jump() {
    cout << "==== jump() Test ====\n";

    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i=0; i < 7; ++i)
        dq.enqueue(eles[i]);
    cout << "start: deque = "; dq.display();
    cout << "start jumping all elements, expected jump(insert in front each time) sequence is 7 -> 8 -> 9 -> 10\n";
    cout << "Now begin jumping\n";
    for (int i=7; i < 10; ++i) {
        dq.jump(eles[i]);
        cout << "\tnow deque = "; dq.display(); cout << '\n';
    }
}
void test_eject() {
    cout << "==== eject() Test ====\n";

    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    cout << "start: deque = "; dq.display();
    cout << "start ejecting all elements, expected returned's sequence is 9 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0\n";
    dq.display();
    cout << '\n';
    for (int i=10; i > 0; --i) {
        cout << "\tejecting " << dq.eject() <<'\n';
        cout << "\tnow "; dq.display(); cout << '\n';
    }
}

int main() {
    test_enqueue_char();
    cout << '\n';
    test_dequeue_int();
    cout << '\n';
    test_clear();
    cout << '\n';
    test_jump();
    cout << '\n';
    test_eject();
    cout << '\n';
    return 0;
}
