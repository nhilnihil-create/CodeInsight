#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll
#define INF 1e16
#define mod 1000000007
int main(){
    ll n,m;
    cin>>n>>m;
    ll dp[1005][1005];
    rep(i,1005)rep(j,1005) {
        if(i==j) dp[i][j] = 0;
        else dp[i][j] = -INF;
    }
    ll a,b,c;
    rep(i,m) {
        cin>>a>>b>>c;
        a--;
        b--;
        dp[a][b] = c;
        // dp[b][a] = c;
    }
    // 経由 // 始点 // 終点
    rep(k,n+1) rep(i,n+1) rep(j,n+1) dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]);
    if(dp[0][0]>0) cout<<"inf"<<endl;
    else cout<<dp[0][n-1]<<endl;
    return 0;
}