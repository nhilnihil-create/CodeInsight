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

vector<vector<vector<ll>>> dp(110, vector<vector<ll>>(110,vector<ll>(410)));

int main(){
    ll N,W;
    cin >> N >> W;
    rep(i,110) rep(j,110) rep(k,410) dp[i][j][k] = 0;
    vector<ll> v(N),w(N);
    rep(i,N){
       cin >> w[i] >> v[i];
    }
    ll base = w[0];
    rep(i,N){
       w[i] -= base;
    }
    rep(i,N) {
       rep(j,N) {
          rep(k,410) {
            if(w[i] <= k){
             dp[i+1][j+1][k] = max(dp[i][j][k-w[i]] + v[i],dp[i][j+1][k]);
            }else{
             dp[i+1][j+1][k] = dp[i][j+1][k];
            }
         }
      }
   }
   ll ans = 0;
   rep(i,N+1){
      if(W - i*base < 0) break;
      ans = max(ans,dp[N][i][min(W-base*i,3*N)]);
   }
   cout << ans << endl;
}
