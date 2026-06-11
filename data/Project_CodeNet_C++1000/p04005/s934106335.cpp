#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t A, B, C;
    cin >> A >> B >> C;
    if (A % 2 != 0 && B % 2 != 0 && C % 2 != 0) {
        int64_t min_ = min({A, B, C});
        int64_t max_ = max({A, B, C});
        int64_t middle = A + B + C - min_ - max_;
        cout << middle * min_ << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}