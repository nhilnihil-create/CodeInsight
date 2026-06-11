//file_name:ABC62_D.cpp
#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

    // int scan
    /*
    int x;
    scanf("%d",&x);
    int y;
    scanf("%d",&y);
    int z;
    scanf("%d",&z);

    // matrix scan
    /*
    ll a[n] = {};
    rep(i,n){
        scanf("%lld",&a[i]);
    }
    */

    // string scan
    /*
    string s;
    cin >> s;
    */


int main() {
    int n;
    cin >> n;
    ll a[3*n];
    rep(i,3*n){
        cin >> a[i];
    }

    ll sum[n+1] = {};

    priority_queue<ll> q;
    rep(i,n){
        sum[0] += a[i];
        q.push(-a[i]);
    }

    rep(i,n){
        sum[i+1] = sum[i];
        sum[i+1] += a[n+i];
        q.push(-a[n+i]);
        sum[i+1] -= -q.top();
        q.pop();
    }

    ll sum2[n+1] = {};
    priority_queue<ll> q2;
    for(int i=3*n-1;i>=2*n;i--){
        sum2[n] += a[i];
        q2.push(a[i]);
    }

    srep(i,1,n+1){
        sum2[n-i] = sum2[n-i+1];
        sum2[n-i] += a[2*n-i];
        q2.push(a[2*n-i]);
        sum2[n-i] -= q2.top();
        q2.pop();
    }

    ll ans = -99999999999999;

    rep(i,n+1){
        //cout << sum[i] << ' ' << sum2[i] << endl;
        ans = max(ans,sum[i]-sum2[i]);
    }

    cout << ans << endl;
    return 0;
}

