#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, M; cin >> N >> M;
    ll res = 0;
    if (N * 2 <= M) {
        res += N;
        M -= 2 * N;
        N = 0;

        res += M/4;
    } else {
        res += M/2;
    }
    cout << res << endl;
}
