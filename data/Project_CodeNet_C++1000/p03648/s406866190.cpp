#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;

const ll MAX_N = ll(1e16) + 1000;

bool check(const vector<ll>& a) {
    for (ll x : a) {
        if (x < 0 || x > MAX_N) return false;
    }
    return true;
}

int main() {
#if __APPLE__
    // freopen("D.in", "r", stdin);
    // freopen("D.out", "w", stdout);
#endif

    ll k;
    scanf("%lld", &k);

    for (ll n = 50; n >= 2; --n) {
        vector<ll> a(n);
        ll cnt = k / n;
        ll rem = k % n;
        for (int i = 0; i < rem; ++i) {
            a[i] = n - 1 + (cnt + 1) * n - ((n - 1) * cnt + rem - 1);
        }
        for (int i = rem; i < n; ++i) {
            a[i] = n - 1 + cnt * n - ((n - 1) * cnt + rem);
        }
        if (check(a)) {
            printf("%d\n", int(n));
            for (ll x : a) {
                printf("%lld ", x);
            }
            puts("");
            return 0;
        }
    }
}
