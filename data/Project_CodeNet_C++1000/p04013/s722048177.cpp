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
ll INF = 214748364700000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

ll dp[60][60][2500];

int main(){
   ll N,A;cin >> N >> A;
   vector<ll> X(N);
   rep(i,N) cin >> X[i];
   dp[0][0][0] = 1;
   rep(i,N){
       rep(j,N+1){
           rep(k,2501){
               dp[i+1][j+1][k+X[i]] += dp[i][j][k];
               dp[i+1][j][k] += dp[i][j][k];
           }
       }
   }
   ll ans = 0;
   FOR(i,1,N+1) rep(k,2501){
       if(A * i == k) ans += dp[N][i][k];
   }
   cout << ans << endl;
}

