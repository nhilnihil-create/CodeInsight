#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}
 
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

ll fact[MAXN];
ll inv_fact[MAXN];

ll binpow(ll a, ll n) {
    if(n == 0) return 1;
    ll res = 1;
    while(n > 0) {
        if(n % 2 == 1) res = (res*a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

ll inverse(ll a) {
    // inv(a) = a^(MOD-2) % MOD
    return binpow(a, MOD-2);
}

int main() {
    FAST_IO();
    int N; cin >> N;
    vector<int> A(N+1);
    vector<int> cnt(N);
    rep(i, N+1) cin >> A[i];
    rep(i, N+1) cnt[A[i]-1]++;
    int v, i1 = -1, i2 = -1;
    rep(i, N) if(cnt[A[i]-1] > 1) v = A[i];
    rep(i, N+1) {
        if(A[i] == v && i1 == -1) i1 = i;
        if(A[i] == v && i1 != -1) i2 = i;
    }
    fact[0] = 1;
    inv_fact[0] = 1;
    repp(i, 1, N+1) {
        fact[i] = fact[i-1] * i % MOD;
        inv_fact[i] = inverse(fact[i]);
    }
    // repp(i, 0, N+1) cout << fact[i] << "\t" << inv_fact[i] << "\n";
    int M = N - 1 - (i2 - i1 - 1);
    repp(K, 1, N + 1) {
        // N+1CK - MCK-1
        ll res = fact[N+1] * inv_fact[K] % MOD * inv_fact[N+1-K] % MOD;
        if(K - 1 <= M) res = (res + MOD - fact[M] * inv_fact[K-1] % MOD * inv_fact[M-K+1] % MOD) % MOD;
        cout << res << "\n";
    }
}