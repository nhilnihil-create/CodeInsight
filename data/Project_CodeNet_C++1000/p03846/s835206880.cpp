#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A.at(i);
    sort(begin(A), end(A));
    ll MOD = (ll)pow(10,9) + 7;
    map<ll,int> MAP;
    ll res = 1;
    ll cur, pos;
    if (N % 2 == 1) {
        if (A[0] != 0 || (N > 1 && A[1] == 0)) {
            cout << 0 << endl;
            return 0;
        }
        cur = 2; pos = 1;
    } else {
        cur = 1; pos = 0;
    }
    for (; pos < N; pos += 2) {
        if (A[pos] == A[pos + 1] && A[pos] == cur) {
            res *= 2;
            res = res % MOD;
        } else {
            cout << 0 << endl;
            return 0;
        }
        cur += 2;
    }
    cout << res << endl;
}
