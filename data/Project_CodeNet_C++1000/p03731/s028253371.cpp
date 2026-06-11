#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, T; cin >> N >> T;
    vector<ll> t(N);
    rep(i, N) cin >> t.at(i);
    ll sum = T;
    for (int i = N-1; i > 0; i--) {
        ll d = t[i] - t[i-1];
        sum += min(d, T);
    }
    cout << sum << endl;
}
