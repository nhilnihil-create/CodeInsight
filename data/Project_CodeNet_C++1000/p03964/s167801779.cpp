#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n;
int main() {
    cin >> n;
    long long x = 1; long long y = 1;
    for(int i = 0; i < n; ++i) {
        long long t, a;
        cin >> t >> a;
        long long m = max((x+t-1)/t, (y+a-1)/a);
        x = t*m; y = a*m;
        // cout << x << " " << y << endl;
    }
    cout << x+y << endl;
}