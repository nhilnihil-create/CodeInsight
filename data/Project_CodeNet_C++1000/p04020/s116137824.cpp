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
  int n;
  cin >> n;
  ll ans = 0;
  ll tmp;
  ll num = 0;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    ans += tmp / 2;
    if(tmp > 0) {
      num += tmp % 2;
      if(num >= 2) {
        ans += num / 2;
        num = 0;
      }
    } else {
      num = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}