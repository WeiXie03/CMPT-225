#include <iostream>
#include "Deque.h"
using namespace std;

void test_enqueue_char() {
    Deque<char> dq;
    string eles = "afe.f,ah,o.t+3fr";
    for (char c : eles) {
        dq.enqueue(c);
    }
    dq.display();
}
void test_enqueue_int() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.display();
}
void test_dequeue_int() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.display();
    cout << "==beginning dequeuing==\n";
    for (int i : eles) {
        cout << "\tdequeued " << dq.dequeue() <<'\n';
    }
    cout << "now "; dq.display(); cout << '\n';
}
void test_clear() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.display();
    cout << "==clearing now==\n";
    dq.clear();
    dq.ddisplay();
}

int main() {
    //test_enqueue_int();
    //test_dequeue_int();
    test_clear();
    return 0;
}
