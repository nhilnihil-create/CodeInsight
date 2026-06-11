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
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl
#define INF 1e16

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long N, long long K, std::vector<long long> a) {
  vl accB(N + 1);
  vl accW(N + 1);
  rep(n, N) {
    accB[n + 1] = accB[n];
    accW[n + 1] = accW[n];
    if (a[n] > 0) {
      accB[n + 1] += a[n];
    } else {
      accW[n + 1] += a[n];
    }
  }

  ll all = accB[N] - accB[0];
  ll maxNum = -INF;
  for (ll i = 0; i <= N - K; i++) {
    // 白で塗る -> 黒で塗られているところの点数を減らす
    ll tmp1 = all - (accB[i + K] - accB[i]);

    // 黒で塗る
    ll tmp2 = all + (accW[i + K] - accW[i]);

    maxNum = max(maxNum, max(tmp1, tmp2));
  }

  print(maxNum);
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}
