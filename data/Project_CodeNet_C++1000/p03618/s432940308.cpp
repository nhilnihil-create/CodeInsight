#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  string t;
  cin >> t;
  
  ll n = t.size();
  
  ll al[30] = {};
  rep(i, n) al[int(t[i] - 'a')]++;
  ll ans = 0;
  rep(i, int('z'-'a') + 1) ans += al[i] * (al[i] + 1LL) / 2LL;
  cout << 1LL + n * (n + 1LL) / 2LL - ans << endl;
  
  return 0;

}
