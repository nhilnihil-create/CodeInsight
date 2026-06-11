#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int dia = a[0];
  auto makePath = [] (int dia) {
    vector<int> res;
    for (int i = dia; i >= (dia + 1) / 2; i--) res.push_back(i);
    for (int i = dia / 2 + 1; i <= dia; i++) res.push_back(i);
    sort(res.rbegin(), res.rend());
    return res;
  };
  vector<int> path = makePath(dia);
  int m = (int) path.size();
  vector<int> done(n);
  int j = 0;
  for (int i = 0; i < m; i++) {
    for (; j < n && a[j] > path[i]; j++);
    if (a[j] < path[i]) {
      cout << "Impossible\n";
      return 0;
    }
    done[j++] = 1;
  }
  // for (int i = 0; i < n; i++) cerr << a[i] << " " ;
  // cerr << endl;
  // for (int i = 0; i < n; i++) cerr << done[i] << " " ;
  // cerr << endl;
  for (int i = 0; i < n; i++) {
    if (!done[i] && (dia + 1) / 2 + 1 > a[i]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  cout << "Possible\n";
  return 0;
}