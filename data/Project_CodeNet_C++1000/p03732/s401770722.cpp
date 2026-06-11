#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
ll sz(string &s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

ll dp[101][101][301] = {};
int main(){
    ll n,W;
    cin >> n >> W;
    ll w[n],v[n];
    
    ll wmemo = 0;
    rep(i,0,n){
        cin >> w[i] >> v[i];
        if(i == 0) wmemo = w[i];
        w[i] -= wmemo;
    }

    rep(i,1,n+1){
        rep(j,1,n+1){
            rep(k,0,301){
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                if(k-w[i-1] >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-w[i-1]]+v[i-1]);
            }
        }
    }

    ll ans = 0;
    rep(j,0,n+1) rep(k,0,301) if(j*wmemo+k <= W) ans = max(ans,dp[n][j][k]);
    
    cout << ans << endl;
    
    return 0;
}
