#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d; cin >> a >> b >> c >> d;
  int s1 = a*b;
  int s2 = c*d;
  if(s1>=s2) cout << s1 << endl;
  else if(s1<s2) cout << s2 << endl;
  
  return 0;
}