#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int m = max(max(a,b),c);
  string ans;
  if(m==a+b+c-m) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}