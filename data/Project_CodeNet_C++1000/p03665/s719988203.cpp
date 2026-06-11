#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, P; cin >> N >> P;
    int odd = 0;
    rep(i,N) {
        int a; cin >> a;
        if (a % 2 == 1) odd++;
    }
    ll res = 0;
    res = (odd == 0) ? ((P == 1) ? 0 : 1LL << N) : 1LL << N-1;
    cout << res << endl;
}
