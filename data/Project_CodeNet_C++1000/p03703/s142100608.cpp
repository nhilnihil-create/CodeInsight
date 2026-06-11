#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n,k;
ll sum[200010];
template<typename T>
struct BIT {
int n;
vector<T> d;
BIT(int n=0):n(n),d(n+1) {}
void add(int i, T x=1) {
for (i++; i <= n; i += i&-i) {
d[i] += x;
}
}
T sum(int i) {
T x = 0;
for (i++; i; i -= i&-i) {
x += d[i];
}
return x;
}
};
int main(){
    BIT<ll> bit(200010);
    cin>>n>>k;
    vl a(n);rep(i,n)cin>>a[i];
    rep(i,n){
        a[i]-=k;
        sum[i+1]=sum[i]+a[i];
    }
    vl v;
    rep(i,n+1)v.pb(sum[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll ans=0;
    for(int i=0;i<=n;i++){
        auto it=lower_bound(v.begin(),v.end(),sum[i])-v.begin();
        ans+=bit.sum(it);
        //cout<<bit.sum(it)<<endl;
        bit.add(it,1);
    }
    cout<<ans<<endl;
    return 0;
}