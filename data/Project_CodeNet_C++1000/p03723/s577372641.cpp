#include <bits/stdc++.h>
using namespace std;

int64_t A, B, C;

int cookieclicker() {
    int64_t res = 0;
    for (int i = 0; i < 100; i++) {
        if (A % 2 != 0) return i;
        if (B % 2 != 0) return i;
        if (C % 2 != 0) return i;
        
        int64_t tA = (B + C) / 2;
        int64_t tB = (C + A) / 2;
        int64_t tC = (A + B) / 2;
        A = tA; B = tB; C = tC;
    }
    return -1;
}

int main() {
    cin >> A >> B >> C;
    cout << cookieclicker() << endl;
}