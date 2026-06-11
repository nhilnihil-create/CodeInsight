#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long resx = 0;
    for(int i=0; i<n; ++i) {
        long long tmp;
        cin >> tmp;
        resx -= (n - (2 * i) - 1) * tmp;
        resx %= MOD;
    }
    long long resy = 0;
    for(int i=0; i<m; ++i) {
        long long tmp;
        cin >> tmp;
        resy -= (m - (2 * i) - 1) * tmp;
        resy %= MOD;
    }

    cout << (resx * resy) % MOD << endl;
}