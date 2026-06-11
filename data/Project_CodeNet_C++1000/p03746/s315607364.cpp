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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void calc(vl &ans, int start, int N, map<ll, vl> &edges) {
  vector<bool> checked(N + 1);
  ll pre = start;

  ans.push_back(pre);
  checked[pre] = true;

  while (true) {
    bool ok = false;
    for (ll v : edges[pre]) {
      if (!checked[v]) {
        pre = v;
        ans.push_back(pre);
        checked[pre] = true;
        ok = true;
        break;
      }
    }

    if (!ok) {
      break;
    }
  }

  reverse(all(ans));
  pre = start;
  while (true) {
    bool ok = false;
    for (ll v : edges[pre]) {
      if (!checked[v]) {
        pre = v;
        ans.push_back(pre);
        checked[pre] = true;
        ok = true;
        break;
      }
    }

    if (!ok) {
      break;
    }
  }
}

void solve(long long N, long long M, std::vector<long long> A,
           std::vector<long long> B) {
  map<ll, vl> edges;
  rep(i, M) {
    edges[A[i]].push_back(B[i]);
    edges[B[i]].push_back(A[i]);
  }

  vl ans;
  calc(ans, A[0], N, edges);

  print(ans.size());
  rep(v, ans.size()) {
    cout << ans[v];
    if (ans.size() - 1 != v) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> A(M);
  std::vector<long long> B(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &A[i]);
    scanf("%lld", &B[i]);
  }
  solve(N, M, std::move(A), std::move(B));
  return 0;
}
