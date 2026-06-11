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
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){
    ll n,m,r;
    cin >> n >> m >> r;
    
    ll d[n][n] = {};
    rep(i,0,n) rep(j,0,n) if(i != j) d[i][j] = LINF;

    ll memo[r] = {};
    rep(i,0,r){
        cin >> memo[i];
        memo[i]--;
    }

    rep(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(k,0,n) rep(i,0,n) rep(j,0,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    
    ll dp[(ll)pow(2,r)][r] = {};
    rep(i,1,(ll)pow(2,r)) rep(j,0,r) dp[i][j] = LINF;

    rep(i,0,r) dp[(1 << i)][i] = 0;
    
    rep(i,0,pow(2,r)){
        rep(j,0,r){
            rep(k,0,r){
                if((i >> k) & 1) continue;
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k],dp[i][j] + d[memo[j]][memo[k]]);
            }
        }
    }
    
    ll ans = LINF;
    rep(i,0,r) ans = min(ans,dp[(ll)pow(2,r)-1][i]);

    cout << ans << endl;
    return 0;
}
