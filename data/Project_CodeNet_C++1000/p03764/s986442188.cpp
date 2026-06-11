#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
const long long MOD = 1000000007;

long long C(long long a) {
    return a * (a - 1) / 2;
}

int main() {
    while (cin >> n >> m) {
        long long xsum = 0;
        long long cx = 0; cin >> cx;
        for (int i = 0; i < n-1; ++i) {
            long long tmp = C(n) - C(i+1) - C(n-1-i);
            long long x; cin >> x;
            xsum += (x - cx) * tmp % MOD;
            xsum %= MOD;
            cx = x;
        }
        long long ysum = 0;
        long long cy = 0; cin >> cy;
        for (int i = 0; i < m-1; ++i) {
            long long tmp = C(m) - C(i+1) - C(m-1-i);
            long long y; cin >> y;
            ysum += (y - cy) * tmp % MOD;
            ysum %= MOD;
            cy = y;
        }
        cout << (xsum * ysum) % MOD << endl;
    }
}


