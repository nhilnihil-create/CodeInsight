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
#include <map>
#include <complex>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int n;
  ll a[150000];
  cin >> n;
  rep(i, n) cin >> a[i];

  ll ans = a[0] - 1;
  ll k = 2;
  for (int i = 1; i < n; i++) {
    if (a[i] == k) k++;
    if (a[i] % k == 0) ans += a[i] / k - 1;
    else ans += a[i] / k;
  }

  cout << ans << endl;

  return 0;

}
