#include <bits/stdc++.h>

using namespace std;

int a[501*501];
int x[501];
int n;

pair<int, int> v[501];

void no() {
  cout << "No\n";
  exit(0);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    v[i] = {x[i], i};
  }
  sort(v + 1, v + n + 1);
  int last = 1;
  for (int i = 1; i <= n; i++) {
    a[v[i].first] = v[i].second;
    for (int j = 0; j < v[i].second - 1; j++) {
      while (a[last] != 0) last++;
      if (last >= v[i].first) no();
      a[last] = v[i].second;
    }
  }
  
  last = n*n;
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < n - v[i].second; j++) {
      while (a[last] != 0) last--;
      if (last <= v[i].first) { no(); }
      a[last] = v[i].second;
    }
  }
  
  cout << "Yes\n";
  for (int i = 1; i <= n * n; i++) {
    cout << a[i] << ' ';
  }

  return 0;
}