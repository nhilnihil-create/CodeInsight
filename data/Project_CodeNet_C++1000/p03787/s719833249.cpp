#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<int(n); i++)
#define all(c) (c).begin(), (c).end()
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N, M;
int C;
int U[100000], R[100000];
vector<int> G[100000];
int V[100000];

int find(int x) {
  if (U[x] == x) return x;
  return U[x] = find(U[x]);
}

void unite(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  if (R[x] < R[y]) swap(x, y);
  U[y] = x;
  R[x] += R[y];
  R[y] = 0;
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int dfs(int x, int p, int l) {
  if (V[x] != -1) return V[x] ^ l;
  V[x] = l;

  int s = -1;
  for (int t : G[x]) {
    if (t == p) continue;
    s = max(s, dfs(t, x, l^1));
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  for (int i=0; i<N; i++) U[i] = i, R[i] = 1, V[i] = -1;
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
    unite(u, v);
  }
  long long s = 0;
  int a = 0, b = 0, c = 0;
  rep(i, N) {
    int n = R[i];
    if (n == 0) continue;
    if (n == 1) c++;
    else {
      int l = dfs(i, -1, 0);
      if (l == 1) b++;
      else a++;
    }
  }
  s += 1LL*a*a;
  s += 1LL*(a+b)*(a+b);
  s += 2LL*N*c - (1LL*c*c);
  cout << s << "\n";
  return 0;
}
