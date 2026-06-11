#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int Q, H, S, D;
    cin >> Q >> H >> S >> D;
    int min_one = min({4 * Q, H * 2, S});
    int64_t N;
    cin >> N;
    if (D > 2 * min_one) {
        cout << N * min_one << endl;
    } else {
        int64_t amari = N % 2;
        int64_t syou = N / 2;
        cout << (amari * min_one) + (syou * D) << endl;
    }
    return 0;
}