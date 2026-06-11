#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int MAX = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<int> graph[MAX];
int fennec[MAX], snuke[MAX];
bool used[MAX];

void dfs1(int v, int d) {
  fennec[v] = d;
  used[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (used[to]) continue;

    dfs1(to, d + 1);
  }
}

void dfsN(int v, int d) {
  snuke[v] = d;
  used[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    int to = graph[v][i];
    if (used[to]) continue;

    dfsN(to, d + 1);
  }
}

int main() {
  // 入力
  int N;
  cin >> N;
  int a[N-1], b[N-1];
  for (int i = 0; i < N - 1; i++) cin >> a[i] >> b[i];

  for (int i = 0; i < N - 1; i++) {
    a[i]--, b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }

  // 頂点0、N-1からのDFSで各頂点までの最短距離を求める
  dfs1(0, 0);
  fill(used, used + MAX, false);
  dfsN(N-1, 0);

  int f = 0, s = 0;
  for (int i = 1; i < N - 1; i++) {
    if (fennec[i] <= snuke[i]) f++;
    else s++;
  }

  // 解答
  cout << (f > s ? "Fennec" : "Snuke") << endl;

  return 0;
}
