#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a <= c && b > c) cout << min(b, d) - c << "\n";
  else if (c <= a && d > a) cout << min(b, d) - a << "\n";
  else cout << 0 << "\n";
}
