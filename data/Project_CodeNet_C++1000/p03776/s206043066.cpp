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
ll c[51][51];
void comb(ll n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i){
                c[i][j]=1ll;
            }
            else c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}
int main(){
    ll n,a,b;cin>>n>>a>>b;
    vl v(n);rep(i,n)cin>>v[i];
    comb(n);
    sort(v.rbegin(),v.rend());
    ld mx=0;
    rep(i,a){
        mx+=v[i];
    }
    mx/=a;
    ll num=0,pos=0;
    rep(i,n){
        if(v[i]==v[a-1]){
            num++;
            if(i<a) pos++;
        }
    }
    ll ans=0;
    if(pos==a){
        for(pos=a;pos<=b;pos++){
            ans+=c[num][pos];
        }
    }
    else ans+=c[num][pos];
    cout.precision(10);
    cout<<fixed<<mx<<endl;
    cout<<ans<<endl;
    return 0;
}