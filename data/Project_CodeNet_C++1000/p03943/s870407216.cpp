#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  vector<int> v(3);
  for (int i = 0; i < 3; ++i) cin >> v[i];

  sort(begin(v), end(v));

  if (v[0] + v[1] == v[2]) cout << "Yes" << "\n";
  else cout << "No" << "\n";
}

	