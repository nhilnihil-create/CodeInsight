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

const int N = 2e3 + 10;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 1e18 + 10, cur = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        cur += a[i];
    }
    for (int cnt = 0; cnt <= n - 1; cnt++) {
        ans = min(ans, cur + 1ll * cnt * x);
        for (int i = 1; i <= n; i++) {
            int j = (i - cnt - 1 + n) % n;
            if (!j) j = n;
            if (b[i] > a[j]) {
                cur += a[j] - b[i];
                b[i] = a[j];
            }
        }
    }
    cout << ans << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
