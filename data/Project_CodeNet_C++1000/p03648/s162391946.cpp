#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INF = 9 * 1e18;
const ll MOD = 1e9 + 7;

void solve(long long K) {
  ll base = 49 + K / 50;
  ll rest = K % 50;
  ll num1 = base + 50 - (rest - 1);
  ll num2 = base - rest;

  ll N = 50;
  vl ans(N);
  rep(i, 0, N) {
    if (i < rest) {
      ans[i] = num1;
    } else {
      ans[i] = num2;
    }
  }

  print(N);
  rep(i, 0, N) {
    cout << ans[i];
    if (i != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  long long K;
  scanf("%lld", &K);
  solve(K);
  return 0;
}
