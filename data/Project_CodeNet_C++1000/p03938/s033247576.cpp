#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<long long, long long> mp;
    for (int i = 1; i <= n; ++i) {
        long long p;
        cin >> p;
        mp[p] = i;
    }

    // a[n]の出力
    for (long long i = 1; i <= n; ++i) {
        cout << n * i;
        (i == n) ? (cout << endl) : (cout << " ");
    }

    // b[n]の出力
    for (long long i = 1; i <= n; ++i) {
        cout << -n * i + mp[i] + n * n;
        (i == n) ? (cout << endl) : (cout << " ");
    }
    return 0;
}