#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    ll a, b; cin >> a >> b;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    // k 回の攻撃ですべての魔物を倒せるか？
    auto ok = [&](ll k) {
        ll c = 0;
        for (int i = 0; i < n; i++) {
            ll rest = max(0LL, h[i] - k * b);
            c += (rest + a - b - 1) / (a - b);
        }
        return c <= k;
    };

    ll l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (ok(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}
