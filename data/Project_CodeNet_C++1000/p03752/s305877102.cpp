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
int main(){
    ll n,k;cin>>n>>k;
    vl b(n);rep(i,n)cin>>b[i];
    ll ans=LINF;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int bit=0;bit<(1<<n);bit++){
        ll cnt=__builtin_popcountll(bit);
        if(cnt<k)continue;
        ll mx=0;
        ll cost=0;
        for(int i=0;i<n;i++){
            if((bit>>i)&1){
                if(mx>=b[i]){
                    cost+=mx-b[i]+1;
                    mx++;
                }
            }
            chmax(mx,b[i]);
        }
        //cout<<bit<<" "<<cost<<endl;
        chmin(ans,cost);
    }
    cout<<ans<<endl;
    return 0;
}