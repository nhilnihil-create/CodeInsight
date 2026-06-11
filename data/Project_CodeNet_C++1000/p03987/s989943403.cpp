#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef __int128_t LL;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

struct segment_tree_max {
    static const int N = 2e5 + 5;
    int t[2 * N + 5];
    void update(int pos, int val) {
        for (t[pos += N] = val; pos > 1; pos >>= 1) {
            t[pos >> 1] = max(t[pos], t[pos ^ 1]);
        }
    }
    int get(int l, int r) {
        int res = 0;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (!(r & 1)) res = max(res, t[r--]);
        }
        return res;
    }
} tree_max;

struct segment_tree_min {
    static const int N = 2e5 + 5;
    static const int inf = 1e9 + 10;
    int t[2 * N + 5];
    void init() {
        for (int i = 0; i < 2 * N + 5; i++) {
            t[i] = inf;
        }
    }
    void update(int pos, int val) {
        for (t[pos += N] = val; pos > 1; pos >>= 1) {
            t[pos >> 1] = min(t[pos], t[pos ^ 1]);
        }
    }
    int get(int l, int r) {
        int res = inf;
        for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (!(r & 1)) res = min(res, t[r--]);
        }
        return res;
    }
} tree_min;

const int N = 2e5 + 10;
int a[N], lef[N], rig[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        lef[i] = max(0, tree_max.get(1, a[i] - 1));
        tree_max.update(a[i], i);
    }
    tree_min.init();
    for (int i = n; i >= 1; i--) {
        rig[i] = min(n + 1, tree_min.get(1, a[i] - 1));
        tree_min.update(a[i], i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * (i - lef[i]) * (rig[i] - i) * a[i];
    }
    cout << ans << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
