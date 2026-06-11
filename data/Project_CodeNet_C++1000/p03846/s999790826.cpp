#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;  cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int a;  cin >> a;
        ++mp[a];
    }
    for (auto e : mp) {
        if (e.second != 2 && !(N % 2 && !e.first)) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << pow_mod(2, N / 2) << endl;
}
