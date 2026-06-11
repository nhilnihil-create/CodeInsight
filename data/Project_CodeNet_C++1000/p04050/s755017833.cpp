/**
 *    author:  tourist
 *    created: 25.01.2020 21:05:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<vector<int>> p(2);
  for (int i = 0; i < m; i++) {
    p[a[i] & 1].push_back(a[i]);
  }
  if (p[1].size() > 2) {
    cout << "Impossible" << '\n';
    return 0;
  }
  if (p[1].size() == 0) {
    for (int i = 0; i < (int) p[0].size(); i++) {
      if (i > 0) cout << " ";
      cout << p[0][i];
    }
    cout << '\n';
    int cnt = (int) p[0].size() + 1 + (p[0].back() > 2);
    cout << cnt << '\n';
    cout << 1;
    for (int i = 0; i < (int) p[0].size() - 1; i++) {
      cout << " " << p[0][i];
    }
    cout << " " << 1;
    if (p[0].back() > 2) {
      cout << " " << p[0].back() - 2;
    }
    cout << '\n';
    return 0;
  }
  if (p[1].size() == 2) {
    cout << p[1][0];
    for (int i = 0; i < (int) p[0].size(); i++) {
      cout << " " << p[0][i];
    }
    cout << " " << p[1][1] << '\n';
    int cnt = (int) p[0].size() + 1 + (p[1][0] > 1) + (p[1][1] > 1);
    cout << cnt << '\n';
    if (p[1][0] > 1) {
      cout << p[1][0] - 1 << " ";
    }
    cout << 2;
    for (int i = 0; i < (int) p[0].size(); i++) {
      cout << " " << p[0][i];
    }
    if (p[1][1] > 1) {
      cout << " " << p[1][1] - 1;
    }
    cout << '\n';
    return 0;
  }
  cout << p[1][0];
  for (int i = 0; i < (int) p[0].size(); i++) {
    cout << " " << p[0][i];
  }
  cout << '\n';
  int cnt = (int) p[0].size() + 1 + (p[1][0] > 1);
  cout << cnt << '\n';
  if (p[1][0] > 1) {
    cout << p[1][0] - 1 << " ";
  }
  for (int i = 0; i < (int) p[0].size(); i++) {
    cout << p[0][i] << " ";
  }
  cout << 1 << '\n';
  return 0;
}
