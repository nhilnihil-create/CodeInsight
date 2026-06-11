#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

vector<vector<ll>> dp;

int main(){
  int n, m, R;
  cin >> n >> m >> R;
  dp.assign(n, vector<ll>(n, LINF));
  vector<int> r(R);
  for(int i = 0; i < R; ++i){
  	cin >> r[i];
  	--r[i];
  }
  for(int i = 0; i < m; ++i){
  	int a, b;
  	ll c;
  	cin >> a >> b >> c;
  	--a;
  	--b;
  	dp[a][b] = c;
  	dp[b][a] = c;
  }

  for(int k = 0; k < n; ++k){
  	for(int i = 0; i < n; ++i){
  		for(int j = 0; j < n; ++j){
  			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  		}
  	}
  }

  sort(r.begin(), r.end());
  ll ans = LINF;
  do{
  	ll tmp = 0;
  	for(int i = 0; i < R - 1; ++i){
  		tmp += dp[r[i]][r[i + 1]];
  	}
  	ans = min(ans, tmp);
  }while(next_permutation(r.begin(), r.end()));

  cout << ans << endl;
  return 0;
}
