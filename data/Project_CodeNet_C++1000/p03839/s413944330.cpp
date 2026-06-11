/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　RedcoderになるためAtCoderを巡る旅をしてます。

　　　 　＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　   ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣￣/ヽ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define rep(i, n) REP(i, 0, n)                  // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++) // x, x + 1, ..., n-1
#define FOREACH(x, a) for(auto &(x) : (a))

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> v(N + 1, 0);
    rep(i, N) v[i + 1] = v[i] + a[i];
    vector<ll> w(N + 1, 0);
    rep(i, N) w[i + 1] = w[i] + max(a[i], 0);

    ll ans = -INF;
    for(int i = 0; i + K <= N; i++) {
        ll tmp = w[N];
        tmp += max(v[i + K] - v[i], 0LL);
        tmp -= w[i + K] - w[i];
        ans = max(ans, tmp);
    }
    COUT(ans);
}
