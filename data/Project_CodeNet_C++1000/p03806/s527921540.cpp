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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n,ma,mb;
    cin>>n>>ma>>mb;

    Vec a(n);
    Vec b(n);
    Vec c(n);

    rep(i,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    vector<tuple<ll,ll,ll>> v1;
    vector<tuple<ll,ll,ll>> v2;

    rep(i,n){
        if(i<=n/2){
            v1.emplace_back(a[i],b[i],c[i]);
        }else{
            v2.emplace_back(a[i],b[i],c[i]);
        }
    }

    map<P,ll> mp1;
    map<P,ll> mp2;

    ll bitmax = 1LL<<v1.size();
    rep(bit,bitmax){
        ll a,b,c;
        a=b=c=0;
        rep(i,v1.size()){
            if(bit & (1LL<<i)){
                ll xa,xb,xc;
                tie(xa,xb,xc) = v1[i];
                a += xa;
                b += xb;
                c += xc;
            }
        }
        if(mp1.count(mp(a,b))){
            chmin(mp1[mp(a,b)],c);
        }else{
            mp1[mp(a,b)] = c;
        }
    }

    bitmax = 1LL<<v2.size();
    rep(bit,bitmax){
        ll a,b,c;
        a=b=c=0;
        rep(i,v2.size()){
            if(bit & (1LL<<i)){
                ll xa,xb,xc;
                tie(xa,xb,xc) =  v2[i];
                a += xa;
                b += xb;
                c += xc;
            }
        }
        if(mp2.count(mp(a,b))){
            chmin(mp2[mp(a,b)],c);
        }else{
            mp2[mp(a,b)] = c;
        }
    }

    ll ans=INF;
    ll addma = ma;
    ll addmb = mb;

    while(max(ma,mb)<401){
        //dbg(ma);
        Each(p,mp1){
            if(mp2.count(mp(ma-p.fi.fi,mb-p.fi.se))){
                chmin(ans,p.se+mp2[mp(ma-p.fi.fi,mb-p.fi.se)]);
            }
        }
        ma += addma;
        mb += addmb;
    }
    if(ans==INF)ans = -1;
    cout<<ans<<endl;
    return  0;
}
