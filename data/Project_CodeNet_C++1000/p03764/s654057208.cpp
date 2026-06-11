#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1000000000
#define MOD 1000000007
#define mod(x) ((x % MOD) + MOD) % MOD
#define MAX_N 100001
#define MAX_M 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
  ll n, m;
  ll x[MAX_N], y[MAX_M];
  cin >> n >> m;
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (ll i = 0; i < m; i++) {
    cin >> y[i];
  }

  sort(x, x + n);
  sort(y, y + m);

  ll X = 0, Y = 0;
  for (ll i = 1; i < n; i++) {
    X = mod(X + i * (n - i) * (x[i] - x[i-1]));
  }
  for (ll j = 1; j < m; j++) {
    Y = mod(Y + j * (m - j) * (y[j] - y[j-1]));
  }

  cout << mod(X * Y) << endl;

  return 0;
}
