#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using PII = pair<int, int>;
using LL = long long;
using VL = vector<LL>;
using VVL = vector<VL>;
using PLL = pair<LL, LL>;
using VS = vector<string>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}
template<class S, class T>
ostream& operator<<(ostream& os, const pair<S,T>& p){
  return os << p.FF << " " << p.SS;
}
template<class T>
void maxi(T& x, T y){
  if(x < y) x = y;
}
template<class T>
void mini(T& x, T y){
  if(x > y) x = y;
}


const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

LL dp[1000010];
LL acc[1000010];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  LL N; cin >> N;
  dp[N] = acc[N] = N;
  dp[N-1] = N * N % MOD;
  acc[N-1] = (dp[N-1] + dp[N]) % MOD;
  for(int i=N-2;i>=1;--i){
	(dp[i] = (N-1)*(N-i-2)%MOD + N*(i+1)%MOD + acc[i+1] + MOD - dp[i+2]) %= MOD;
	(acc[i] = acc[i+1] + dp[i]) %= MOD;
  }
  cout << dp[1] << endl;

  return 0;
}
