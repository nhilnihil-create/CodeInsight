#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  set<double> water;
  set<double> sugar;
  
  vector<int> dp(3000, 0);
  dp[0] = 1;
  for(int i = 0; i < 30; i++) {
    if(dp[i] == 1) {
      water.insert(i * 100);
      if(i + a < 30) {
        dp[i + a] = 1;
      }
      if(i + b < 30) {
        dp[i + b] = 1;
      }
    }
  }
  for(int i = 0; i<3000; i++){
    dp[i] = 0;
  }

  dp[0] = 1;
  for(int i = 0; i < 3000; i++) {
    if(dp[i] == 1) {
      sugar.insert(i);
      if(i + c < 3000) {
        dp[i + c] = 1;
      }
      if(i + d < 3000) {
        dp[i + d] = 1;
      }
    }
  }
  double per = 0;
  pair<int, int> ans = {0, 0};
  for(auto p : water) {
    if(p == 0){
      continue;
    }
    //cout << p << " ";
    for(auto q : sugar) {
      //cout << q << " ";
      if(p + q > f) {
        break;
      }
      if(p * e < q * 100) {
        break;
      }
      if(per * (p + q) <= 100.0 * q) {
        per = 100.0 * q /(double)(p + q);
        ans.first = p;
        ans.second = q;
      }
    }
    //cout << endl;
  }
  cout << ans.first + ans.second << " " << ans.second << endl;
  return 0;
}
