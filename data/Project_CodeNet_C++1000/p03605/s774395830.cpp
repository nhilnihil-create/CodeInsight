#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n;
  string ans="No";
  cin >> n;
  if(n/10==9) ans="Yes";
  if(n%10==9) ans="Yes";
  cout << ans << endl;
}