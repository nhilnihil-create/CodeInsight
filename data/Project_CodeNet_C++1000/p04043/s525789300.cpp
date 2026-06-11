#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  vector<int> v;
  for (int i = 0; i < 3; ++i) {
    int x;
    cin >> x;
    v.emplace_back(x);
  }

  sort(begin(v), end(v));

  if (v[0] == 5 && v[1] == 5 && v[2] == 7) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
