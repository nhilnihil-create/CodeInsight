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

ll w[105];
ll v[105];
ll dp[105][105][305];
int main(){
    int n;cin >> n;
    ll W;cin >> W;
    rep(i,n) cin >> w[i] >> v[i];
    ll w0=w[0];
    ll ans=0;
    rep(i,n) w[i]-=w0;
    rrep(i,n){
        rrep(j,n){
            rep(k,3*n+1){
                dp[i][j][k]=dp[i-1][j][k];
                if(k-w[i-1]>=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-w[i-1]]+v[i-1]);
                //cout << "i" << i << " " << "j" << j << " " << "k" << k << " " << dp[i][j][k] << endl;
                if(j*w0+k<=W) chmax(ans,dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}