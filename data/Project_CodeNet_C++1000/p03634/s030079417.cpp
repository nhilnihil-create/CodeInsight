#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pa pair<int, int>
#define pal pair<long long, long long>
#define pali pair<long long, int>
#define pad pair<double, double>
#define pb push_back
#define mp make_pair
#define COUT(v)                              \
    for (int64_t i = 0; i < (v).size(); ++i) \
    {                                        \
        cout << v.at(i) << endl;             \
    }
#define REP(i, n) for (int64_t i = 0; i < n; ++i)
#define FOR(i, r, n) for (int64_t i = (r); i < n; ++i)
#define VIN(v)                               \
    for (int64_t i = 0; i < (v).size(); ++i) \
    {                                        \
        cin >> (v).at(i);                    \
    }
 
typedef vector<bool> bvec;
typedef vector<int> ivec;
typedef vector<long long> lvec;
typedef vector<double> dvec;
typedef vector<pa> pavec;
typedef vector<vector<pa> > pamat;
typedef vector<pali> palivec;
typedef vector<pal> palvec;
 
typedef vector<vector<bool> > bmat;
typedef vector<vector<int> > imat;
typedef vector<vector<long long> > lmat;
 
typedef vector<string> svec;
typedef vector<vector<string> > smat;
const ll infll = (1LL << 60) - 1;
const int inf = (1 << 30) - 1;
const ll MOD = 1000000007;
 
ll gcd(ll x, ll y)
{
    ll r = x % y;
    if (r == 0)
        return y;
    else
        return gcd(y, r);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}
 
lvec mfactor(ll n)
{
    bvec ip(n, true);
    lvec mf(n, -1);
    ip[0] = false;
    ip[1] = false;
    mf[0] = 0;
    mf[1] = 1;
    REP(i, n)
    {
        if (ip[i])
        {
            mf[i] = i;
            for (ll j = i * i; j < n; j += i)
            {
                ip[j] = false;
                if (mf[j] == -1)
                    mf[j] = i;
            }
        }
    }
    return mf;
}
 
palivec get_prime(ll n, const lvec &mf)
{
    palivec plist;
    while (n != 1)
    {
        int cnt = 0;
        ll m = mf[n];
        while (mf[n] == m)
        {
            cnt++;
            n /= m;
        }
        plist.pb(pali(m, cnt));
    }
    return plist;
}
 
void COMinit(int m, lvec &fac, lvec &finv)
{
    lvec inv(m);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < m; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
ll pow_mod(ll a, ll n, ll mod = MOD)
{
    ll x = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            x = x * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return x;
}

ll COM(int n, int k, const lvec &fac, const lvec &finv)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;
}
 
ll modinv(ll a, ll m)
{
    ll b = m, u = 1, v = 0;
    while (b)
    {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll> > > g(n);
    for (int i=0; i<n-1; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;        
        g[a].pb(pair<ll, ll>(b, c));
        g[b].pb(pair<ll, ll>(a, c));
    }
    ll q, k;
    cin >> q >> k;
    --k;
    lvec dis(n, -1);
    function<void(ll, ll) > dfs = [&dfs, &dis, &g](ll x, ll d){
        dis[x] = d;        
        for (int i=0; i<g[x].size(); i++){            
            ll ind = g[x][i].first;
            ll w = g[x][i].second;            
            if(dis[ind] == -1) dfs(ind, d+w);
        }
    };
    dfs(k, 0);
    
    lvec ans(q);
    for (int i=0; i<q; i++){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ans[i] = dis[x] + dis[y];
    }
    for (auto v: ans){
        cout << v << '\n';
    }

    
    return 0;
}

