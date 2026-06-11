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
int dp[410][410];
int main(){
    int n,ma,mb;cin >> n >> ma >> mb;
    vi a(n),b(n),c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,410){
        rep(j,410){
            dp[i][j]=INF;
        }
    }
    dp[0][0]=0;
    rep(it,n){
        set<P> ng;
        rep(i,401){
            rep(j,401){
                if(i-a[it]>=0&&j-b[it]>=0){
                    if(!ng.count({i-a[it],j-b[it]})){
                        if(chmin(dp[i][j],dp[i-a[it]][j-b[it]]+c[it])){
                            ng.insert({i,j});
                        }
                    }
                }
            }
        }
    }
    int ans=INF;
    rrep(i,400){
        rrep(j,400){
            if(dp[i][j]!=INF&&i*mb==j*ma){
                chmin(ans,dp[i][j]);
            }
        }
    }
    if(ans==INF){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}