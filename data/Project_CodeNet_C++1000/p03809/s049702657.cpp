#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int imp = 0;
const int N = 1e5;
ll a[N];
vector<int> treeone[N];

bool calc(int i, ll s, ll mx) {
  ll tx;
  if(mx * 2 < s) {
    tx = s / 2;
  } else {
    tx = s - mx;
  }
  return s - a[i] <= tx;
}

ll dfs(int i, int p = -1) {
  if(imp) return -1;
  if(p != -1 && (int) treeone[i].size() == 1) return a[i];
  ll s = 0, mx = 0;

  for(int j : treeone[i]) if(p != j) {
    ll t = dfs(j, i);
    if(imp) return -1;
    mx = max(mx, t);
    s += t;
  }
  // t + (s - t) / 2 = A
  // 2 t + s - t = 2 A
  // t = 2 A - s
  ll t = 2 * a[i] - s;
  if(t < 0 || s - a[i] < 0) {
    imp = 1; return -1;
  }
  bool ok = calc(i, s, mx);
  if(!ok) {
    imp = 1; return -1;
  }
  return t;
}

int solve() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y; x--; y--;
    treeone[x].emplace_back(y);
    treeone[y].emplace_back(x);
  }
  if(n == 2) return a[0] == a[1];
  int x;
  for(int i = 0; i < n; i++) if((int) treeone[i].size() != 1) x = i;
  if(dfs(x) > 0) return 0;
  return !imp;
}

int main() {
  cout << (solve() ? "YES" : "NO") << endl;
}

