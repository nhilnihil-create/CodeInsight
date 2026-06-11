#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;  
  int d = 0;
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    d = max(d, x);
    s.insert(x);
  }
  if (d % 2 == 0) {
    for (int i = d / 2 + 1; i <= d; i++) {
      for (int j = 0; j < 2; j++) {
        if (!s.count(i)) {
          cout << "Impossible\n";
          return 0;
        }
        s.erase(s.find(i));
      }
    }
    if (!s.count(d / 2)) {
      cout << "Impossible\n";
      return 0;
    }
    s.erase(s.find(d / 2));
    for (auto& it : s) {
      if (it < d / 2 + 1) {
        cout << "Impossible\n";
        return 0;
      }
    }
  } else {
    for (int i = d / 2 + 1; i <= d; i++) {
      for (int j = 0; j < 2; j++) {
        if (!s.count(i)) {
          cout << "Impossible\n";
          return 0;
        }
        s.erase(s.find(i));
      }
    } 
    for (auto& it : s) {
      if (it < d / 2 + 2) {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  return 0;
}