#include <bits/stdc++.h>
#define rep(i, x, y) for (long long i = x; i <= y; i++)
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, inf = 1e9 + 7;
ll node[N * 10], ans[15];
ll h, w, n, cnt;

int main() {
    cin >> h >> w >> n;
    ans[0] = 1ll * (h - 2) * (w - 2);
    rep(i, 1, n) {
        ll a, b; cin >> a >> b;
        rep(j, max(1ll, a - 2), min(h - 2, a)) {
            rep(k, max(1ll, b - 2), min(w - 2, b)) {
                node[++cnt] = inf * j + k;
            }
        }
    }
    sort(node + 1, node + cnt + 1);
    ll num = 1;
    rep(i, 1, cnt) {
        if (node[i] == node[i + 1]) num++;
        else ans[num]++, num = 1, ans[0]--;
    }
    rep(i, 0, 9) printf("%lld\n", ans[i]);
    return 0;
}
