#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define SS(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t){cin >> t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First& first, Rest&...rest){cin >> first;MACRO_VAR_Scan(rest...);}
#define _overload3(_1,_2,_3,name,...) name
#define _REP(i,n) REPI(i,0,n)
#define REPI(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define REP(...) _overload3(__VA_ARGS__,REPI,_REP,)(__VA_ARGS__)
ll MOP(ll a,ll b,ll mod=1e9+7) {ll c=1ll;do{if(b&1)c*=1ll*a%mod;a*=1ll*a%mod;}while(b>>=1);return c;}
#define ln '\n'

//---------------8<---------------8<---------------8<---------------8<---------------//

ll dp[5050][5050];

signed main() {

  SS(int,N);
  SS(string,s);
  int s_len = s.size();

  dp[0][0] = 1;
  REP(i,N) REP(j,N) {
    (dp[i+1][j+1] += dp[i][j]*2) %= MOD;
    (dp[i+1][j-(j!=0)] += dp[i][j]) %= MOD;
  }

  ll res = dp[N][s_len];
  REP(i,s_len) (res *= (MOD+1)/2) %= MOD;
  cout << res << ln;

}