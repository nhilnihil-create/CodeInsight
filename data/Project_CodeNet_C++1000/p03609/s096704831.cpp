#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x,t,ans;
  cin >> x >> t;
  if (x<t) ans=0;
  else ans=x-t;
  cout << ans << endl;
}