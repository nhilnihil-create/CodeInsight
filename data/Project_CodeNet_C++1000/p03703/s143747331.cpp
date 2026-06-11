/// IN THE NAME OF METAL
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md, ll ans = 1) {
    for (; b; b >>= 1, a = a * a % md)
        if (b & 1)
            ans = ans * a % md;
    return ans % md;
}

const ll MAXN = 1e6 + 10;
const ll INF = 818;
const ll MOD = 1e9 + 7;
ll ind[MAXN], fen[MAXN], A[MAXN], ps[MAXN], ans = 0, n, P;
vector<ll> compress;

void update(ll ind, ll val) {
    for (; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

ll get(ll ind, ll res = 0) {
    for (; ind; ind -= ind & -ind) res += fen[ind];
    return res;
}

int main() {
    scanf("%lld%lld", &n, &P);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
    }
    for (ll i = 1; i <= n; i++) {
        A[i] -= P;
    }
    partial_sum(A, A + MAXN, ps);
    for (ll i = 0; i <= n; i++) {
        compress.push_back(ps[i]);
    }
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    for (ll i = 0; i <= n; i++) {
        ind[i] = lower_bound(all(compress), ps[i]) - compress.begin() + 1;
        ans += get(ind[i]);
        update(ind[i], 1);
    }
    printf("%lld", ans);
    return 0;
}

