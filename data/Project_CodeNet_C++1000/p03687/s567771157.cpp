#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  vector<vector<int>> ch(26);
  for (int i = 0; i < N; i++) {
    ch[s[i]-'a'].push_back(i);
  }
  int ans = N;
  for (auto v : ch) {
    int k = v.size();
    if (k == 0) continue;
    int d = max(v[0],N-1-v[k-1]);
    for (int i = 0; i < k; i++) d = max(v[i]-v[i-1]-1,d);
    ans = min(ans,d);
  }
  cout << ans << endl;
}