#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  string a, b, c;
  cin >> a >> b >> c;

  if (a.back() == b.front() && b.back() == c.front()) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
