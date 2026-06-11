#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int W, H, N;
    cin >> W >> H >> N;
    int x_start = 0;
    int y_start = 0;
    for (int i=0; i<N; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1 && x > x_start) {
            x_start = x;
        } else if (a == 2 && W > x) {
            W = x;
        } else if (a == 3 && y > y_start) {
            y_start = y;
        } else if (a == 4 && H > y) {
            H = y;
        }
    }

    if (y_start >= H || x_start >= W) {
        cout << 0 << endl;
    } else {
        cout << (W - x_start) * (H - y_start) << endl;
    }

    return 0;
}