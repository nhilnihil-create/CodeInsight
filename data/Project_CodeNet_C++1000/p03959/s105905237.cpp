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

  int n;
  ll t[100010] = {}, a[100010] = {};
  cin >> n;
  rep(i, n) cin >> t[i + 1];
  rep(i, n) cin >> a[i + 1];

  ll ans = 1;
  rep(i, n) {
    if (t[i] < t[i + 1]) {
      if (a[i + 2] < a[i + 1]) {
	if (a[i + 1] != t[i + 1]) {
	  cout << 0 << endl;
	  return 0;
	}
      } else {
	if (t[i + 1] > a[i + 1]) {
	  cout << 0 << endl;
	  return 0;
	}
      }
    } else {
      if (a[i + 2] < a[i + 1]) {
	if (a[i + 1] > t[i + 1]) {
	  cout << 0 << endl;
	  return 0;
	}
      } else {
	ans *= min(t[i + 1], a[i + 1]);
	ans %= MOD;
      }
    }
  }
  cout << ans << endl;

  return 0;

}
