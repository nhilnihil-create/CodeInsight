#include <bits/stdc++.h>
using namespace std;
int n, m;
bool ck (int k, vector<vector<int>>& a) {
  set<int> st;
  for (int j = 0; j < m; j++) st.insert(j);
  vector<int> pos(n, 0);
  while (true) {
    multiset<int> mlt;
    int sus = -1;
    for (int i = 0; i < n; i++) {
      int crr = a[i][pos[i]];
      mlt.insert(crr);
      if (mlt.count(crr) > k) {
        sus = crr;
        break;
      }
    }
    if (sus == -1) return true;
    st.erase(sus);
    for (int i = 0; i < n; i++) {
      for (int j = pos[i]; j <= m; j++) {
        if (j == m) return false;
        if (st.find(a[i][j]) != st.end()) {
          pos[i] = j;
          break;
        }
      }
    }
  }
}
int main() {
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int ng(0), ok(n), md;
  while (ok - ng > 1) {
    md = (ng + ok) >> 1;
    if (ck(md, a)) ok = md;
    else ng = md;
  }
  cout << ok << endl;
  return 0;
}