#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,c,ans;
  string b;
  cin >> a >> b >> c;
  if (b == "+") ans = a + c;
  else if (b == "-") ans = a - c;
  cout << ans << endl;
}