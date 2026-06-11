#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  
  pair<int, int> ans = {0, 0};

  int mn;
  cin >> mn;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    if (ans.first < a - mn) {
      ans.first = a - mn;
      ans.second = 0;
    }
    if (ans.first == a - mn) {
      ans.second++;
    }
    mn = min(mn, a);
  }
  
  cout << ans.second << "\n";
  return 0;
}
