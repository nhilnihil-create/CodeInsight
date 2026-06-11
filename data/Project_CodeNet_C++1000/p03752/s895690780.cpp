#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    // 1) N == K;
    ll base;
    ll cost = INF;

    for (int i = 0; i < (1 << (N - 1)); i++) {
        // cout << i << endl;
        vector<ll> other;
        ll tmp = 0;
        base = a[0];
        set<ll> st;
        for (int j = 0; j < (N - 1); j++) {
            if (i >> j & 1) {
                // other.push_back(a[j + 1]);
                st.insert(j + 1);
            }
        }
        // cout << endl;
        // cout << "sze:" << other.size() << endl;
        if (st.size() != K - 1) continue;

        ll prev_high = base;
        for (int k = 1; k < N; k++) {
            if (st.count(k)) {
                // 選ぶ
                if (prev_high + 1 <= a[k]) {
                    prev_high = a[k];
                } else {
                    prev_high++;
                    tmp += prev_high - a[k];
                }
            } else {
                // 選ばない
                prev_high = max(prev_high, a[k]);
            }
            // cout << tmp << endl;
        }
        cost = min(cost, tmp);
    }

    cout << cost << endl;
}