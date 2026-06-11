#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll dp[50][510][510];

int main(){
    ll N,MA,MB;
    cin >> N >> MA >> MB;
    rep(i,50) rep(j,510) rep(k,510) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,N){
        ll a,b,c;
        cin >> a >> b >> c;
        rep(j,410){
            rep(k,410){
                dp[i+1][j+a][k+b] = min(dp[i][j+a][k+b],dp[i][j][k] + c);
                dp[i+1][j][k] = min(dp[i][j][k],dp[i+1][j][k]);
            }
        }
    }
    ll ans = INF;
    rep(i,410) rep(j,410){
        if(i * j == 0) continue;
        if(i * MB == j * MA) ans = min(ans,dp[N][i][j]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}
