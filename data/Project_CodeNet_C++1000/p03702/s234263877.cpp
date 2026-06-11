#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    rep(i, N) cin >> h[i];
    ll ans_min = 0, ans_max = 1e9;
    while (ans_min + 1 < ans_max) {
        ll ans = (ans_min + ans_max) / 2;
        ll count = 0;
        rep(i, N) if (h[i] - B * ans > 0) count += (h[i] - B * ans + A - B - 1) / (A - B);
        if (count > ans) ans_min = ans;
        else ans_max = ans;
    }
    cout << ans_max << endl;
    return;
}

int main() {
    solve();
}