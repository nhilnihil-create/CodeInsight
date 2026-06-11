#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin>>n>>m;
  int a[n][m];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin>>a[i][j];
      --a[i][j];
    }
  }
  set<int> sports;
  for (int i=0; i<m; i++) sports.insert(i);

  int idx[n];
  for (int i=0; i<n; i++) idx[i] = 0;

  int ans = n;
  while (sports.size() > 1) {
    int cnt[m];
    for (int i=0; i<m; i++) cnt[i] = 0;
    for (int i=0; i<n; i++) {
      ++cnt[a[i][idx[i]]];
    }
    pair<int, int> max_v = make_pair(-1, 0);
    for (int i=0; i<m; i++) {
      if (cnt[i] > max_v.second) {
        max_v = make_pair(i, cnt[i]);
      }
    }
    ans = min(max_v.second, ans);
    sports.erase(max_v.first);

    for (int i=0; i<n; i++) {
      while (sports.find(a[i][idx[i]]) == sports.end()) {
        ++idx[i];
      }
    }
  }
  cout<<ans<<endl;
}