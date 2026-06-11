#define TEMPLATE_USED
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
}

void solve(){
    ll n,ma,mb;cin>>n>>ma>>mb;
    vl a(n),b(n),c(n);
    rep(i,n)cin>>a[i]>>b[i]>>c[i];

    vvl dp(500,vl(500,INF));
    dp[0][0]=0;
    rep(i,n){
        rrep(j,500)rrep(k,500){
            if(j-a[i]<0||k-b[i]<0)continue;
            chmin(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
        }
    }
    ll ans=INF;
    rep(i,1,min(500/ma,500/mb)){
        chmin(ans,dp[i*ma][i*mb]);
    }
    cout<<(ans==INF?-1:ans)<<endl;
}