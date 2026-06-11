#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define REP(i, r) for(int i = (int)0; i < (int)r; ++i)
#define FORD(i, l, r) for(int i = (int)l; i >= (int)r; --i)
#define REPD(i, r) for(int i = (int)r - 1; i >= 0; --i)
#define X first
#define Y second
#define debug(x) {cerr << #x << " = " << x << '\n';}
#define pr(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define pr0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int Nmax = 2e5 + 11;
const ll MOD = 1e9 + 7;

ll n, m, a, b, inv[Nmax], p[Nmax];

ll power(ll a, ll k) {
    if (k == 0) return 1;
    ll tmp = power(a, k / 2);
    if (k % 2 == 1) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(ll k, ll n) {
    if (k > n) return 0;
    return ((p[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

int main() {
//    freopen("D.inp", "r", stdin);
    cin >> n >> m >> a >> b;
    p[0] = 1;
    FOR(i, 1, Nmax - 1) p[i] = (p[i - 1] * i) % MOD;
    inv[Nmax - 1] = power(p[Nmax - 1], MOD - 2);
    FORD(i, Nmax - 1, 1) {
        inv[i - 1] = (inv[i] * i) % MOD;
    }
    ll ans = C(m - 1, n + m - 2);
    FOR(i, n - a, n - 1) {
        ans = (ans - C(b - 1, i + b - 1) * C(n - 1 - i, m + n - 2 - i - b) + MOD * MOD) % MOD;
    }
    cout << ans;
}
