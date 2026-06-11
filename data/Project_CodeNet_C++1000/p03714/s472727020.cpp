#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N * 3);
    rep(i, N * 3) cin >> a[i];

    // 左から累積和を取る
    vector<ll> S(N * 2 + 1, 0);
    priority_queue<ll, vector<ll>, greater<ll>> q1;
    rep(i, N) {
        S[i + 1] = S[i] + a[i];
        q1.push(a[i]);
    }
    for (int i = N; i < N * 2; i++) {
        S[i + 1] = S[i] + a[i];
        q1.push(a[i]);

        S[i + 1] -= q1.top();
        q1.pop();
    }

    // 右から累積和を取る
    vector<ll> T(N * 2 + 1, 0);
    priority_queue<ll> q2;
    rep(i, N) {
        T[i + 1] = T[i] + a[N * 3 - 1 - i];
        q2.push(a[N * 3 - 1 - i]);
    }
    for (int i = N; i < N * 2; i++) {
        T[i + 1] = T[i] + a[N * 3 - 1 - i];
        q2.push(a[N * 3 - 1 - i]);

        T[i + 1] -= q2.top();
        q2.pop();
    }

    ll ans = -(1LL << 60);
    for (int i = N; i <= N * 2; i++) chmax(ans, S[i] - T[N * 3 - i]);
    cout << ans << endl;
}