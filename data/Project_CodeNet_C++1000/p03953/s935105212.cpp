#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for (int i = x; i >= y; i--)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, m, K, pos[N], a[N], b[N], vis[N], p[N], ans[N];

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%lld", &pos[i]), b[i] = i;
    per(i, n, 1) pos[i] -= pos[i - 1];
    cin >> m >> K;
    rep(i, 1, m) scanf("%lld", &a[i]), swap(b[a[i]], b[a[i] + 1]);
    rep(i, 1, n) if (!vis[i]) {
        int cnt = 0;
        int j = i;
        for (; !vis[j]; j = b[j]) {
            vis[j] = 1;
            p[++cnt] = j;
        }
        rep(j, 1, cnt) ans[p[j]] = pos[p[(j + K % cnt - 1) % cnt + 1]];
    }
    rep(i, 1, n) ans[i] += ans[i - 1], printf("%lld.0\n", ans[i]);
    return 0;
}
