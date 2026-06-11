#include <bits/stdc++.h>
using namespace std;

vector<int> a1(2e5), a2(2e5), r1(2e5, 0), r2(2e5, 0);
void init(int n) {
  for (int i = 0; i < n; i++) a1[i] = a2[i] = i;
}
int find1(int x) {
  if (a1[x] == x) return x;
  return a1[x] = find1(a1[x]);
}
int find2(int x) {
  if (a2[x] == x) return x;
  return a2[x] = find2(a2[x]);
}
void unite1(int x, int y) {
  x = find1(x), y = find1(y);
  if (x == y) return;
  if (r1[x] < r1[y]) {
    a1[x] = y;
  } else {
    a1[y] = x;
    if (r1[x] == r1[x]) r1[x]++;
  }
}
void unite2(int x, int y) {
  x = find2(x), y = find2(y);
  if (x == y) return;
  if (r2[x] < r2[y]) {
    a2[x] = y;
  } else {
    a2[y] = x;
    if (r2[x] == r2[y]) r2[x]++;
  }
}
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int n, k, l; cin >> n >> k >> l;
  init(n);
  for (int i = 0; i < k; i++) {
    int p, q; cin >> p >> q;
    p--; q--;
    unite1(p, q);
  } 
  for (int i = 0; i < l; i++) {
    int r, s; cin >> r >> s;
    r--; s--;
    unite2(r, s);
  }
  for (int i = 0; i < n; i++) a1[i] = find1(i), a2[i] = find2(i);
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) mp[pair<int, int>(a1[i], a2[i])]++;
  for (int i = 0; i < n; i++) cout << mp[pair<int, int>(a1[i], a2[i])] << ' ';
  cout << '\n';
  return 0;
}