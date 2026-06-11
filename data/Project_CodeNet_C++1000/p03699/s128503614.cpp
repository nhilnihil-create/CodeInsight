#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N;
    cin >> N;
    int min_ = INT_MAX;
    int sum_ = 0;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        if (x % 10 != 0) {
            if (min_ > x) {
                min_ = x;
            }
        }

        sum_ += x;
    }

    if (sum_ % 10 != 0) {
        cout << sum_ << endl;
    } else {
        if (INT_MAX > min_) {
            sum_ -= min_;
            cout << sum_ << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}