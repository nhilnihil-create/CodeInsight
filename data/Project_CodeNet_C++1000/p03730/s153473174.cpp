#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    vector<bool>amari(B, false);
    bool is_can = false;
    int count = 2;
    int moto_A = A;
    while (true) {
        if (A % B == C) {
            is_can = true;
            break;
        } else if (amari[A%B]) {
            break;
        }

        amari[A%B] = true;
        A = moto_A * count;
        count++;
    }

    if (is_can) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}