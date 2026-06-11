#include<bits/stdc++.h>

using namespace std;

#define int long long

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

signed main()
{
  int N, M, U[200000], V[200000];

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    cin >> U[i] >> V[i];
  }

  UnionFind tree2(N + N), tree3(N);
  for(int i = 0; i < M; i++) {
    tree2.unite(U[i] + N, V[i]);
    tree2.unite(V[i] + N, U[i]);
    tree3.unite(U[i], V[i]);
  }

  int other = 0, one = 0, two = 0;
  for(int i = 0; i < N; i++) {
    if(tree3.find(i) == i) {
      if(tree3.size(i) == 1) ++other;
      else if(tree2.find(i) != tree2.find(i + N)) ++two;
      else ++one;
    }
  }

  int latte = other * N * 2 - other * other;
  cout << latte + two * two * 2 + one * one + two * one * 2 << endl;
}