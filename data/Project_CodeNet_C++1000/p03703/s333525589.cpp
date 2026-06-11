#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};





template<class T>
struct BIT {
    ll n;
    vector<T> bit;

    BIT(ll num) : bit(num+1, 0) { n = num; }

    void add(ll i, T w) {
        for (ll x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }

    T sum(ll i) {
        T ret = 0;
        for (ll x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
};



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Timer TM;

    ll n,k;
    ll a[200010]={};
    ll sum[200010]={};
    cin>>n>>k;
    rep(i,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll b[200010]={};
    b[0]=0;
    rep2(i,1,n+1){
        b[i]=sum[i]-i*k;
    }
    ll c[200010]={};
    rep(i,n+1) c[i]=b[i];
    sort(c,c+n+1);
    map<ll,ll> m;
    rep(i,n+1) m[c[i]]=i+1;
    BIT<ll> bit(n+1);
    ll ans=0;
    rep(j,n+1){
        ans += bit.sum(m[b[j]]);
        bit.add(m[b[j]],1);
    }
    cout<<ans<<endl;


    
    return 0;
}