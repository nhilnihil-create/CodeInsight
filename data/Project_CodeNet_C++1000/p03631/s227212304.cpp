#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int x; cin >> x;
  vector<int> v;

  for (int i = 0; i < 3; ++i) {
    v.push_back(x % 10);
    x /= 10;
  }

  if (v.front() == v.back()) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}
