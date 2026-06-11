// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
int nmax=200000;
vvec g(nmax);

ll ans=INF;
int m;
void saiki(vec idx,vvec &a,vector<bool> f){
    vector<int> mp(m);
    int n=idx.size();
    rep(i,n){
        mp[a[i][idx[i]]]++;
    }
    vec sa;
    int ma=0;
    rep(i,m) chmax(ma,mp[i]);
    chmin(ans,ma);
    rep(i,m){
        if(ma==mp[i]) sa.pb(i);
    }
    vec next=idx;
    for(int k:sa){
        f[k]=true;
        rep(i,n){
            while(f[a[i][next[i]]]){
                next[i]++;
                if(next[i]==m) return;
            }
        }        
    }
    saiki(next,a,f);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;
    cin>>n>>m;
    vvec a(n,vec(m));
    rep(i,n) rep(j,m) cin>>a[i][j],a[i][j]--;
    vec idx(n);
    vector<bool> f(m,false);
    saiki(idx,a,f);
    
    cout<<ans<<endl;
}