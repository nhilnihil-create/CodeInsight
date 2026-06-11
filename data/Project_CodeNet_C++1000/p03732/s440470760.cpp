#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

ll dp[101][301][101];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; ll W; cin>>n>>W;
    vll w(n),v(n);
    rep(i,n) cin>>w[i]>>v[i];
    ll w0 = w[0];
    rep(i,n) w[i]-=w0;
    rep(i,n)FOR(j,0,300)FOR(k,0,n){
        if (j>=w[i] && k>=1){
            if (dp[i][j-w[i]][k-1]+v[i] > dp[i][j][k]){
                dp[i+1][j][k] = dp[i][j-w[i]][k-1]+v[i];
            }else{
                dp[i+1][j][k] = dp[i][j][k];
            }
        }else{
            dp[i+1][j][k] = dp[i][j][k];
        }
    }
    ll ans=0;
    FOR(j,0,300)FOR(k,0,n){
        if (w0*k+j<=W) chmax(ans,dp[n][j][k]);
    }
    cout<<ans<<endl;
    return 0;
}
