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

const int MAX = 2e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

// 素集合データ構造
struct UnionFind {
  vector<int> par, sizes; // par:あるデータの親, sizes:あるデータが属する木のサイズ

  // コンストラクタ
  // データ一つ一つを木とし、親は自分自身に初期化する
  UnionFind(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; i++) par[i] = i;
  }

  // データxが属する木の根ノードを取得
  // 再帰的に根を調べる際に、調べた辺を根に直接繋ぎ直すことで効率化している（経路圧縮）
  int find(int x) {
    return (x == par[x] ? x : par[x] = find(par[x]));
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // それぞれのデータの根ノードを取得
    x = find(x);
    y = find(y);

    // x, yが同じ木に属するならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるようにマージする
    par[y] = x;
    sizes[x] += sizes[y];
  }

  // 2つのデータx, yが同じ木に属するかどうか
  bool same(int x, int y) {
    return (find(x) == find(y));
  }

  // データxの属する木のサイズを返す
  int size(int x) {
    return sizes[find(x)];
  }
};

int main() {
  // 入力
  int N, K, L;
  cin >> N >> K >> L;
  int p[K], q[K];
  for (int i = 0; i < K; i++) cin >> p[i] >> q[i];
  int r[L], s[L];
  for (int i = 0; i < L; i++) cin >> r[i] >> s[i];

  UnionFind uf_k(N);
  UnionFind uf_l(N);
  for (int i = 0; i < K; i++) {
    p[i]--, q[i]--;
    uf_k.unite(p[i], q[i]);
  }
  for (int i = 0; i < L; i++) {
    r[i]--, s[i]--;
    uf_l.unite(r[i], s[i]);
  }

  int ar[MAX];
  int br[MAX];
  for (int i = 0; i < N; i++) {
    ar[i] = uf_k.find(i);
    br[i] = uf_l.find(i);
  }

  map<P, int> mp;
  for (int i = 0; i < N; i++) {
    mp[P(ar[i], br[i])]++;
  }

  // 解答
  cout << mp[P(ar[0], br[0])];
  for (int i = 1; i < N; i++) {
    cout << " " << mp[P(ar[i], br[i])];
  }
  cout << endl;

  return 0;
}
