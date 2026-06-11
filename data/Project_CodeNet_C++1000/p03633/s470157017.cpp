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
  ll ans = 1;
  for(int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << endl;
  return 0;
}