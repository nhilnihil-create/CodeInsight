#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}