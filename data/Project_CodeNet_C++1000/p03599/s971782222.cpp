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
  vector<double> water;
  vector<double> sugar;
  a *= 100;
  b *= 100;
  for(int i = 0; i < f + 1; i++) {
    if(i * a > f){
      break;
    }
    for(int j = 0; j < f + 1; j++) {
      if(a * i + b * j <= f) {
        water.push_back(a * i + b * j);
      }else{
        break;
      }
    }
  }
  vector<int> dp(3000, 0);
  dp[0] = 1;
  for(int i = 0; i < f + 1; i++) {
    if(i * c > f){
      break;
    }
    for(int j = 0; j < f + 1; j++) {
      if(j * d + i * c <= f){
        sugar.push_back(j * d + i * c);
      }else{
        break;
      }
    }
  }
  double maxi = 0;
  pair<int, int> ans = {0, 0};
  for(auto p : water) {
    
    //cout << p << " ";
    for(auto q : sugar) {
      if(p + q == 0){
        continue;
      }
      //cout << q << " ";
      if(p + q > f) {
        continue;
      }
      double per = (double) q /(double)(p + q);
      /*
      if(per > e / (100. + e)) { //e * p/100 < q
        continue;
      }
      */
      if(maxi <= per && per <= e / (100. + e)) { // per < 100 * q / (p + q)
        maxi = per;
        ans.first = p;
        ans.second = q;
      }
    }
    //cout << endl;
  }
  cout << ans.first + ans.second << " " << ans.second << endl;
  return 0;
}