#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;

int par[2][200001];

void init(int n) {
  for (int i = 1; i <= n; i++) {
    par[0][i] = par[1][i] = i;
    }
}

int find(int i, int x) {
  if (par[i][x] == x) return x;
  return par[i][x] = find(i, par[i][x]);
}

void unite(int i, int x, int y) {
  x = find(i, x);
  y = find(i, y);
  if (x != y) par[i][x] = y;
}

int main(void) {
  int n, K, L, x, y;
  cin >> n >> K >> L;

  init(n);
  for (int i = 0; i < K; i++) {
    cin >> x >> y;
    unite(0, x, y);
  }
  for (int i = 0; i < L; i++) {
    cin >> x >> y;
    unite(1, x, y);
  }

  map<P, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[P(find(0, i), find(1, i))]++;
  }

  for (int i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    cout << mp[P(find(0, i), find(1, i))];
  }
  cout << endl;
  
  return 0;
}