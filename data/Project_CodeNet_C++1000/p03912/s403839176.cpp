#ifdef LOCAL
//#define _GLIBCXX_DEBUG
#endif
//#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;
typedef vector<vector<vector<ll>>> VVV;
typedef vector<vector<vector<vector<ll>>>> VVVV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define rEach(i, mp) for (auto i = mp.rbegin(); i != mp.rend(); ++i)
#ifdef LOCAL
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define dbgarrmint(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j].x<<" ";}cerr<<endl;}
#else
#define dbg(...)
#define dbgmap(...)
#define dbgarr(...)
#define dbgdp(...)
#define dbgmint(...)
#define dbgarrmint(...)
#endif
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,v.size())i>>v[j];return i;}

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

int solve(){
    ll n,m;
    cin>>n>>m;
    Vec a(n);
    cin>>a;
    VV g(m);

    //si,doのペア
    VP vp(m);

    vector<set<ll>> gst(m);
    rep(i,n){
        ll j = a[i]%m;
        g[a[i]%m].pb(a[i]);
        if(gst[j].count(a[i])){
            gst[j].erase(a[i]);
            vp[j].fi--;
            vp[j].se++;
        }else{
            gst[j].insert(a[i]);
            vp[j].fi++;
        }
    }
    dbg(g);
    dbg(vp);
    ll ans = 0;

    auto sub = [&](P &p,ll sub){
        ll odd = p.fi;
        ll pair = p.se;
        ll minusodd = min(sub,odd);
        ll over = sub-minusodd;
        p.fi -= minusodd;
        p.se -= (over+1)/2;
        if(over%2==1) p.fi++;
    };
    REP(i,1,(m-1)/2 + 1){
        ll j = m-i;
        dbg(mp(i,j));
        ll lc = vp[i].fi+vp[i].se*2;
        ll rc = vp[j].fi+vp[j].se*2;
        ll mi = min(lc,rc);
        sub(vp[i],mi);
        sub(vp[j],mi);
        dbg(mp(lc,rc));
        dbg(mi);
        ans += mi;
    }
    {
        ll cnt = vp[0].fi+vp[0].se*2;
        cnt = cnt/2;
        ans += cnt;
        sub(vp[0],cnt*2);
    }
    if(m%2==0){
        ll cnt = vp[m/2].fi+vp[m/2].se*2;
        cnt = cnt/2;
        ans += cnt;
        sub(vp[m/2],cnt*2);
    }

    dbg(vp);
    dbg(ans);
    rep(i,m) ans += vp[i].se;
    out(ans);
    return  0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);
    solve();
}
