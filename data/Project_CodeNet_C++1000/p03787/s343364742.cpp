#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


int main() {
  int N, M, U[200000], V[200000];

  cin >> N >> M;
  UnionFind latte(N + N), malta(N);
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    latte.unite(x + N, y);
    latte.unite(y + N, x);
    malta.unite(x, y);
  }

  int64 uku = 0, one = 0, two = 0;
  for(int i = 0; i < N; i++) {
    if(malta.find(i) != i) continue;
    if(malta.size(i) == 1) ++uku;
    else if(latte.find(i) != latte.find(i + N)) ++two;
    else ++one;
  }
  cout << (uku * N + two * (one + two)) * 2 - uku * uku + one * one << endl;
}

