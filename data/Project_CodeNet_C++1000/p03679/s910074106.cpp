#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,a,b;
  cin >> x >> a >> b;
  string ans;
  if(a>=b) ans="delicious";
  else {
    if(b-a>=x+1) ans="dangerous";
    else ans="safe";
  }
  cout << ans << endl;
  return 0;
}
  