#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
# include <map>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

vector<vector<ll>> dp(100, vector<ll>(100, -1));

ll dfs(int n, int k){
  if (dp[n][k]!=-1) return dp[n][k];
  if (k==0||k==n) return dp[n][k] = 1;
  else return dp[n][k] = (dfs(n-1, k-1) + dfs(n-1, k));
}

int main() {
  int N, A, B; cin >> N >> A >> B;
  map<ll, int> v; rep(i,N) {ll n; cin >> n; v[n]++;}
  rep(i, 51) dfs(50,i);

  ll sum = 0, c = 0, A_t = A;
  long double ave = 0;
  for (auto i=v.rbegin(), e=v.rend(); i!=e; i++) {
    if (i==v.rbegin() && A_t <= i->second) {
      ave = i->first;
      for (int x=A_t; x<=min(B,i->second); x++) {
        c += dp[i->second][x];
      }
      break;
    }

    if (A_t>=i->second) {
      sum += i->first * i->second;
      A_t -= i->second;
    }
    else {
      sum += i->first * A_t;
      ave = (long double)sum / A;
      c = dp[i->second][A_t]; 
      break;
    }
  }
  cout<< fixed << setprecision(10) << ave << endl;
  cout << c << endl;
  return 0;
}