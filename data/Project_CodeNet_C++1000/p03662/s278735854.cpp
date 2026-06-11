#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }

int sz[100001];
int depth[100001];
int N;
int T;

int dfs(int v, int p, vector<vector<int>> &G, int d) {
  int ret = 1;
  depth[v] = d;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    ret += dfs(G[v][i], v, G, d + 1);
  }
  return sz[v] = ret;
}

int dfs2(int v, int p, vector<vector<int>> &G, int d, int d_search) {
  if (v == N - 1) return 1;

  int ret = 0;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    int r = dfs2(G[v][i], v, G, d + 1, d_search);
    ret |= r;
    if (r == 1 && d + 1 == d_search) {
      T = G[v][i];
    }
  }
  return ret;
}

void solve() {
  cin >> N;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0, -1, G, 0);
  dfs2(0, -1, G, 0, depth[N - 1] / 2 + 1);
  int szB = sz[T];
  int szA = N - szB;
  if (szA > szB) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(16);
  solve();
  return 0;
}