#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef string str;
static const long long INF = 1LL<<59;
static const long long MOD = (ll)1e9+7;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define REP(i, n) for(ll i=0;i<n;i++)
#define SZ(v) (ll)((v).size())
#define WHOLE(v) (v).begin(), (v).end()
#define ASC(v) sort((v).begin(), (v).end())
#define DESC(v) sort((v).rbegin(), (v).rend())
#define INV(v) reverse((v).begin(), (v).end())
#define FOLDL(src, dst, lambda) partial_sum((src).begin(), (src).end(), (dst).begin(), lambda)
#define FOLDR(src, dst, lambda) INV(src);partial_sum((src).begin(), (src).end(), (dst).begin(), lambda);INV(dst)
#define CUMSUML(src, dst) FOLDL(src, dst, [](auto a, auto b) {return a+b;})
#define CUMSUMR(src, dst) FOLDR(src, dst, [](auto a, auto b) {return a+b;})
#define ACCUM(v, d0, lambda) accumulate((v).begin(), (v).end(), d0, lambda)
#define SUM(v, d0) ACCUM(v, d0, [](auto a, auto b) {return a+b;})
#define ERASE(v, i) v.erase(v.begin() + i)
#define UNIQ(v) ASC(v);v.erase(unique(v.begin(), v.end()), v.end())

template <typename T>void debug(T t) {cerr << t << endl;}
template <typename T, typename ...Args>void debug(T t, Args ...args) {cerr << t << " ";debug(args...);}
template <typename T>void out(T t) {cout << t << endl;}
template <typename T, typename ...Args>void out(T t, Args ...args) {cout << t << " ";out(args...);}

void solve() {
    ll N, K;
    cin >> N >> K;
    vll A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];
    vll Ks;
    Ks.push_back(K);
    ll bit = 0;
    ll tmp = K;
    while(tmp >= 1) {
        tmp >>= 1;
        bit++;
    }
    for(ll k = bit; k >= 0; k--) {
        ll mask = ~(1 << k);
        ll p = 0;
        for(ll q = k - 1; q >= 0; q--) {
            p |= (1 << q);
        }
        if (((K&mask)|p) <= K)
            Ks.push_back((K&mask)|p);
    }
    UNIQ(Ks);
    ll ans = -INF;
    for(auto &k:Ks) {
        ll tmp = 0;
        REP(i, N) {
            if((k|A[i])==k) {
                tmp+=B[i];
            }
        }
        ans = max(ans, tmp);
    }
    out(ans);
}

int main() {
    fast_io;
    solve();
    return 0;
}