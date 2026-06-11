#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;cin>>x>>a>>b;
  string ans;
  if (a - b >= 0) ans = "delicious";
  else if ((b - a) - x <= 0) ans = "safe";  
  else ans = "dangerous";
  cout << ans << endl;
}