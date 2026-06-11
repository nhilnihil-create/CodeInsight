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
    string s,t;cin>>s>>t;
    ll n=sz(s),m=sz(t);
    vl sum1A(n+1),sum1B(n+1),sum2A(m+1),sum2B(m+1);
    ll q;cin>>q;
    rep(i,n){
        sum1A[i+1]=sum1A[i]+(s[i]=='A'?1:0);
        sum1B[i+1]=sum1B[i]+(s[i]=='B'?1:0);
    }
    rep(i,m){
        sum2A[i+1]=sum2A[i]+(t[i]=='A'?1:0);
        sum2B[i+1]=sum2B[i]+(t[i]=='B'?1:0);
    }
    rep(i,q){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        ll Y=(sum1A[b]-sum1A[a-1])-(sum1B[b]-sum1B[a-1]);
        ll X=(sum2A[d]-sum2A[c-1])-(sum2B[d]-sum2B[c-1]);
        if((Y-X)%3==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}