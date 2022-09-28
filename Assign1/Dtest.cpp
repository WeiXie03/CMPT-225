#include <iostream>
#include "Deque.h"
using namespace std;

void test_enqueue_char() {
    Deque<char> dq;
    string eles = "afe.f,ah,o.t+3fr";
    for (char c : eles) {
        dq.enqueue(c);
    }
    dq.ddisplay();
}
void test_enqueue_int() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.ddisplay();
}
void test_dequeue_int() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.ddisplay();
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
    dq.ddisplay();
    cout << "==clearing now==\n";
    dq.clear();
    dq.ddisplay();
}
void test_jump() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i=0; i < 7; ++i)
        dq.enqueue(eles[i]);
    cout << "Enqueued some ints, now "; dq.ddisplay();
    cout << "\nNow begin jumping\n";
    for (int i=7; i < 10; ++i) {
        cout << "\tjumping " << eles[i] <<'\n';
        dq.jump(eles[i]);
        cout << "\tnow "; dq.ddisplay(); cout << '\n';
    }
}
void test_eject() {
    Deque<int> dq;
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.display();
    cout << "under the hood: "; dq.ddisplay();
    cout << '\n';
    for (int i=10; i >= 0; --i) {
        cout << "\tejecting " << dq.eject() <<'\n';
        cout << "\tnow "; dq.display(); cout << '\n';
    }
    cout << "under the hood: "; dq.ddisplay();
}

int main() {
    //test_enqueue_char();
    //test_dequeue_int();
    //test_clear();
    //test_jump();
    //test_eject();
    return 0;
}
