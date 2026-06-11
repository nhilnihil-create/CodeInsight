#include <bits/stdc++.h>
using namespace std;

string A, B, C;
void doA();
void doB();
void doC();

void doA() {
    if (A.size() == 0) {
        cout << "A" << endl;
        exit(0);
    }
    string tmp = A;
    A = A.substr(1);
    if (tmp[0] == 'a') {
        doA();
    } else if (tmp[0] == 'b') {
        doB();
    } else {
        doC();
    }
}
void doB() {
    if (B.size() == 0) {
        cout << "B" << endl;
        exit(0);
    }
    string tmp = B;
    B = B.substr(1);
    if (tmp[0] == 'a') {
        doA();
    } else if (tmp[0] == 'b') {
        doB();
    } else {
        doC();
    }
}

void doC() {
    if (C.size() == 0) {
        cout << "C" << endl;
        exit(0);
    }
    string tmp = C;
    C = C.substr(1);
    if (tmp[0] == 'a') {
        doA();
    } else if (tmp[0] == 'b') {
        doB();
    } else {
        doC();
    }
}
int main() {
    cin >> A >> B >> C;

    doA();

    return 0;
}
