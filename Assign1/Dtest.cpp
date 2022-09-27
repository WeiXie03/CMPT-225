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
    int eles[] = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i : eles) {
        dq.enqueue(i);
    }
    dq.display();
}

int main() {
    test_enqueue_int();
    return 0;
}
