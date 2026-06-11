#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  vector<queue<int>> x(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      x.at(i).push(a);
    }
  }
  
  int ans = n;
  vector<bool> used(m + 1, false);
  for (int i = 0; i < m; i++) {
    vector<int> count(m + 1);
    for (int j = 0; j < n; j++) {
      count.at(x.at(j).front())++;
    }
    int maximum = 0, value = 0;
    for (int j = 1; j <= m; j++) {
      if (count.at(j) > maximum) {
        maximum = count.at(j);
        value = j;
      }
    }
    used.at(value) = true;
    ans = min(ans, maximum);
    bool flag = false;
    for (int j = 0; j < n; j++) {
      while (!x.at(j).empty() && used.at(x.at(j).front())) {
        x.at(j).pop();
      }
      if (x.at(j).empty()) flag = true;
    }
    if (flag) break;
  }
  
  cout << ans << '\n';
}