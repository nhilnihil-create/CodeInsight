#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grh(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    grh[--a].push_back(--b);
    grh[b].push_back(a);
  }
  set<int> st;
  vector<int> ret;
  int crr = 0;
  ret.push_back(crr);
  st.insert(crr);
  for (int t = 0; t < 2; t++, crr = 0) {
    for (bool flg = false; ; flg = false){
      for (int nxt : grh[crr]) if (st.insert(nxt).second) {
          if (t == 0) ret.push_back(nxt);
          if (t == 1) ret.insert(ret.begin(), nxt);
          crr = nxt;
          flg = true;
          break;
      }
      if (!flg) break;
    }
  }
  cout << ret.size() << endl;
  for (auto it = ret.begin(); it != ret.end(); it++) {
    cout << *it + 1 << (next(it) == ret.end() ? '\n' : ' ');
  }
  cout << endl;
  return 0;
}