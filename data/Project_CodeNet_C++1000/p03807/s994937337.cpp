#include <iostream>
using namespace std;

int main() {
    int n, a, odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a & 1) ++odd;
        else ++even;
    }
    if (odd & 1) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}