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
  int n, k;
  cin >> n >> k;
  int dis[11] = {};
  for(int i = 0; i < k; i++) {
    int tmp;
    cin >> tmp;
    dis[tmp] = 1;
  }
  int ans = n;
  while(true) {
    int c = ans;
    bool ok = true;
    while(c > 0) {
      if(dis[c % 10] == 0) {
        c /= 10;
        continue;
      } else {
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
  return 0;
}