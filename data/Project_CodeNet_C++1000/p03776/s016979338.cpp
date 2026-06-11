#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<ll, ll>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+18;

ll comb(ll a, ll b) {
    if (b<0 || b>a) return 0LL;
    if (b==0 || b==a) return 1LL;
    ll res = 1LL;
    rep(i, b) {
        res *= (a-i);
        res /= (i+1);
    }
    return res;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(rwhole(v));
    vector<ll> s(n+1);
    rep(i, n) s[i+1] = s[i] + v[i];
    vector<P> x;
    for (ll i=a; i<=b; i++) {
        x.emplace_back(s[i], i);
    }
    P best = P(0LL, 1LL);
    ll num = 0;
    int nx = x.size();
    rep(i, nx) {
        if (x[i].first*best.second>best.first*x[i].second) {
            best = x[i];
        }
    }
    double ans = static_cast<double>(best.first)/static_cast<double>(best.second);
    printf("%.10f\n", ans);
    map<ll, ll> mp;
    rep(i, n) mp[v[i]]++;

    rep(i, nx) {
        if (x[i].first*best.second==best.first*x[i].second) {
            int c = a+i;
            ll th = v[c-1];
            int cnt = 0;
            rep(j, c) {
                if (v[j]==th) cnt++;
            }
            num += comb(mp[th], cnt);
        }
    }
    cout << num << endl;
    return 0;
}
