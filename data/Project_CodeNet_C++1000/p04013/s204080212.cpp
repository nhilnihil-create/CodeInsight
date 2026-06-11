#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 2505;
ll dp[55][MAX];
int main() {
  int n,a;
  cin >> n >> a;
  dp[0][0] = 1;
  rep(i,n){
    int x;
    cin >> x;
    rep(ik,i+1){
      int k = i-ik;
      rep(v,MAX-x) dp[k+1][x+v] += dp[k][v];
    }
  }
  ll ans = 0;
  rep(i,n) ans += dp[i+1][(i+1)*a];
  cout << ans << endl;
}
