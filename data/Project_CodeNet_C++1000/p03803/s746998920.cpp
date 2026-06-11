#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int A,B;
    cin >> A >> B;
    A = (A == 1) ? 14 : A;
    B = (B == 1) ? 14 : B;

    if(A > B) {
        cout << "Alice\n";
    } else if(A < B) {
        cout << "Bob\n";
    } else {
        cout << "Draw\n";
    }
    return 0;
}