// 5/30
// 2-6-1. 線分状の格子点の個数
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

ll gcd(ll a, ll b) {  // bが常にワル役
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;  // 先に割ることでオーバーフローを防げる
}

int main() {
    int N;
    cin >> N;

    vector<ll> T(N);
    rep(i, N) cin >> T[i];

    ll g = T[0];
    rep(i, N - 1) {
        g = lcm(g, T[i + 1]);
    }

    // cout << lcm(1000000000000000000, 1000000000000000000) << endl;

    cout << g << endl;
}
