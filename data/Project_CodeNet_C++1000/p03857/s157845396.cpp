#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int par[2][200010];

int find(int id, int x) {
  if (par[id][x] == x) return x;
  return par[id][x] = find(id, par[id][x]);
}

void unite(int id, int x, int y) {
  x = find(id, x);
  y = find(id, y);
  if (x == y) return;
  par[id][y] = x;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N, K, L;  
  cin >> N >> K >> L;

  for (int i = 0; i < N; i++) {
    par[0][i] = par[1][i] = i;
  }

  for (int i = 0; i < K; i++) {
    int p, q;
    cin >> p >> q;
    p--, q--;
    unite(0, p, q);
  }

  for (int i = 0; i < L; i++) {
    int r, s;
    cin >> r >> s;
    r--, s--;
    unite(1, r, s);
  }

  map<pii, int> mp;
  for (int i = 0; i < N; i++) {
    mp[pii(find(0, i), find(1, i))]++;
  }
  
  for (int i = 0; i < N; i++) {
    cout << mp[pii(find(0, i), find(1, i))] << (i + 1 == N ? '\n' : ' ');
  }

  return 0;
}