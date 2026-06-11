#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int w, a, b;
  cin >> w >> a >> b;

  int diff = abs(a - b);

  if (diff <= w) cout << 0 << "\n";
  else cout << diff - w << "\n";
}
