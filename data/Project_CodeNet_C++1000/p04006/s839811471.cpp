#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int n; ll x;
    cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    
    vector<vector<ll>> m(n+1,vector<ll>(n+1));
    rep(i,n) m[i][0]=a[i];
    
    rep(i,n){
        rep(j,n){
            m[i][j+1]=min(m[i][j],a[(i-j-1+n)%n]);
        }
    }
    
    ll ans=LINF;
    
    rep(k,n){
        ll now=(ll)k*x;
        
        rep(i,n) now+=m[i][k];
        
        ans=min(ans,now);
    }
    
    cout<<ans<<endl;
}