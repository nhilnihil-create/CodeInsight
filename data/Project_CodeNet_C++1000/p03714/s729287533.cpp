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

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n;
    cin>>n;
    Vec a(3*n);
    cin>>a;

    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([&](ll a, ll b){
        return a>b;
    });
    ll ans= -INF;
    ll lsum = 0;
    rep(i,n){
        lsum += a[i];
        q.push(a[i]);
    }

    Vec ldp(n+1);
    ldp[0] = lsum;
    rep(i,n){
        ll x = a[i+n];
        q.push(x);
        ll p = q.top();
        q.pop();
        ldp[i+1] = ldp[i] + x - p;
    }



    Vec rdp(n+1);
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q2([&](ll a, ll b){
        return a<b;
    });
    reverse(ALL(a));

    ll rsum = 0;
    rep(i,n){
        rsum += a[i];
        q2.push(a[i]);
    }

    rdp[0] = rsum;
    rep(i,n){
        ll x = a[i+n];
        q2.push(x);
        ll p = q2.top();
        q2.pop();
        rdp[i+1] = rdp[i] + x - p;
    }

//    dbg(ldp)
//    dbg(rdp)
    rep(i,n+1){
        chmax(ans,ldp[i]-rdp[n-i]);
    }

    cout<<ans<<endl;
    return  0;
}
