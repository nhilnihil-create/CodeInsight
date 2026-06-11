#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll> > P3;

const ll MOD = ll(1e9 + 7);
const ll LLINF = LLONG_MAX;
const int IINF = INT_MAX;
const int MAX_N = int(2e5) + 5;
const int MAX_A = int(15e6);
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
string dir = "RDLU";
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()


ll factrial[MAX_N], inverse[MAX_N];  //階乗と逆元を保持

ll mod_power(ll x, ll n) {  //繰り返し二乗法
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init(ll n) {
    factrial[0] = 1;
    inverse[0] = 1;
    for (ll i = 1; i <= n; i++) {
        factrial[i] = (factrial[i - 1] * i) % MOD;  //階乗を求める
        inverse[i] = mod_power(factrial[i], MOD - 2) % MOD;  //オイラーの定理で逆元を求める
    }
}

ll nCk(ll n, ll k) {
    if(n < 0 || k < 0 || n < k) return 0;
    return factrial[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}


int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;
    init(h+w);
    ll ans = 0;
    for(ll i = h-a-1, j = b; i>=0 && j<=w; i--, j++){
        ans += nCk(i+j,j) * nCk(h+w-i-j-2,w-j-1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
