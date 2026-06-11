#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, M; cin >> N >> M;
    if (abs(N - M) > 1) {
        cout << 0 << endl;
        return 0;
    }

    if (N < M) swap(N, M);
    // N! * M!
    ll MOD = (ll)pow(10,9) + 7;
    ll res = 1;
    bool even = ((N+M) % 2 == 0);
    while (N > 0) {
        res *= N;
        res %= MOD;
        N--;
    } 
    while (M > 0) {
        res *= M;
        res %= MOD;
        M--;
    }
    if (even) {
        res *= 2;
        res %= MOD;
    }
    cout << res << endl;
}
