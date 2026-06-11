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

// ll tri(ll a, ll b) {
//     int x = a / b;
//     int y = a & b;

    


//     // if (b == 0) return a;

//     // return tri(b, a % b) + b;
// }

int main() {
    ll N, X;
    cin >> N >> X;

    ll ans = N;

    ll a = max(N - X, X);
    ll b = min(N - X, X);  // 本当はたぶんa, bはどちらでも良さそう。

    while (true) {
        // cout << ans << endl;
        ll x = a / b;
        ll y = a % b;

        if (y != 0) {
            ans += x * b * 2;  // 一回削るごとにカンカン、と２回bが通る。
            a = b;
            b = y;
        } else {
            ans += (x - 1) * b * 2 + b;
            break;
        }
    }

    cout << ans << endl;
}
