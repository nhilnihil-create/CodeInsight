#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S;
const ll MOD = (1e+9) + 7;
const ll INF = 1000;//1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>W;
    ll w0;
    vec wplus(N,0), v(N);
    cin>>w0>>v[0];
    reps(i,1,N){
        cin>>wplus[i]>>v[i];
        wplus[i] -= w0;
    }
    vector<mat> dp(N+1,mat(N+1, vec(400,-INF)));
    dp[0][0][0] = 0;
    rep(i,N){
        rep(j,N){
            rep(k,400) {
                if (dp[i][j][k] != -INF) {
                    dp[i + 1][j + 1][k + wplus[i]] = max(dp[i + 1][j + 1][k + wplus[i]], dp[i][j][k] + v[i]);
                }
                dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
            }
        }
    }
    ll ans = -INF;
    rep(j,N+1){
        rep(k,400){
            if(j*w0 + k <= W) ans = max(ans, dp[N][j][k]);
        }
    }
    /*rep(i,N){
        rep(j,N){
            rep(k,5) cout<<dp[i][j][k]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }*/
    cout<<ans<<endl;
}