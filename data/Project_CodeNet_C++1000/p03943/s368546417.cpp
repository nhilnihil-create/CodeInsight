#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  string ans;
  if(a + b == c || b + c == a || c + a == b) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}
