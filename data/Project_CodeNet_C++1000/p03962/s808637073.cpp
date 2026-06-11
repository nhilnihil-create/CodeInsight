#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) cout << 1 << "\n";
  else if (a == b || a == c || b == c) cout << 2 << "\n";
  else cout << 3 << "\n";
}
