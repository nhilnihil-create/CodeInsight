#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

ll gcd(ll a, ll b){
  if (a%b == 0){
    return(b);
  }else{
    return(gcd(b, a%b));
  }
}
ll lcm(ll a, ll b){
  return a * (b / gcd(a, b));
}

int main()
{
  ll N;
  cin >> N;

  vector<ll> T(N);
  REP(i, N) cin >> T[i];
  
  ll ans = T[0];
  REP(i,N){
    ans = lcm(ans,T[i]);
  }

  cout << ans << endl;
}