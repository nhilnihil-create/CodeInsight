#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll X; cin >> X;

    if (X <= 6) {cout << 1 << endl; return 0;}
    if (X <= 11) {cout << 2 << endl; return 0;}

    ll Y = X / 11;
    if (X - Y * 11 == 0) cout << Y * 2;
    else if (X - Y * 11 < 7) cout << Y * 2 + 1;
    else cout << Y * 2 + 2;
    cout << endl; 
}
