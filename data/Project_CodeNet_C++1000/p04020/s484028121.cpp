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

const int N = 1e5 + 10;
int a[N];

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
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] >> 1;
        a[i] &= 1;
        if (a[i] && a[i + 1]) {
            ans++;
            a[i]--;
            a[i + 1]--;
        }
    }
    cout << ans << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
