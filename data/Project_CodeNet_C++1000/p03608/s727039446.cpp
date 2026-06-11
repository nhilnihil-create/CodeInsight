#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

ll dp[205][205];
int main(){FIN
    ll n,m,r;cin>>n>>m>>r;
    ll dp[n][n];
    REP(i,n) REP(j,n) dp[i][j] = inf;
    REP(i,n) dp[i][i] = 0;

    
    vll obj(r); REP(i,r) cin>>obj[i];
    REP(i,r) obj[i]--;
    REP(i,m){
        ll a,b,c;cin>>a>>b>>c;
        a--; b--;
        dp[a][b] = c;
        dp[b][a] = c;
    }
    REP(k,n){
        REP(i,n){
            REP(j,n) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
        }
    }
    VSORT(obj);
    ll ans=inf;

    do {
        ll dis=0;
        REP(i,r-1) dis += dp[obj[i+1]][obj[i]];
        // cout<<dis<<endl;
        ans = min(dis, ans);  
    } while(next_permutation(ALL(obj)));

    cout<<ans<<endl;
    // cout<<dp[3][100]<<endl;
    return 0;
}
