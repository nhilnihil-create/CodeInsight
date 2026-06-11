#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n, k;

int main() {
    cin >> n >> k;
    long long ans = k;
    for(int i = 0; i < n-1; ++i) ans *= (k-1);
    cout << ans << endl;
}