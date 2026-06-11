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

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
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
const ll INF = 1e16;

void solve(long long H, long long W, long long N, std::vector<long long> a,
           std::vector<long long> b) {
  map<pll, ll> cnts;
  rep(n, N) {
    for (ll da = -2; da <= 0; da++) {
      for (ll db = -2; db <= 0; db++) {
        ll ax = a[n] + da;
        ll bx = b[n] + db;

        if (ax > 0 && ax <= H - 2 && bx > 0 && bx <= W - 2) {
          cnts[mp(ax, bx)]++;
        }
      }
    }
  }

  vector<ll> counts(10);
  counts[0] = (H - 2) * (W - 2);
  itrep(iter, cnts) {
    counts[0]--;
    if (iter->sc <= 9) {
      counts[iter->sc]++;
    }
  }
  rep(i, 10) { print(counts[i]); }
}

int main() {
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  std::vector<long long> b(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
  }
  solve(H, W, N, std::move(a), std::move(b));
  return 0;
}
