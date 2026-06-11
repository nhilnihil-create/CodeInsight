/**
 *    author:  tourist
 *    created: 13.01.2020 23:29:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    a[i] = i * n + 1;
    b[i] = (n - 1 - i) * n + 1;
  }
  for (int i = 0; i < n; i++) {
    a[p[i]] += i;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << '\n';
  return 0;
}
