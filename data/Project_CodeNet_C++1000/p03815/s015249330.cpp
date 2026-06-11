#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;
  long long ans = x/11 * 2;
  int r = x%11;
  if(r>6) ans += 2;
  else if(r>0)ans += 1;
  
  
  cout << ans << endl;
}
