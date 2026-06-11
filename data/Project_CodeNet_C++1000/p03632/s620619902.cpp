#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int a,b,c,d,ans;
  cin >> a >> b >> c >> d;
  if(c>a) {
    if(d>b) ans = b - c;
    else ans = d - c;
  }
  else {
    if(b>d) ans = d - a;
    else ans = b - a;
  }
  if(c>b) ans = 0;
  if(a>d) ans = 0;
  cout << ans << endl;
    
}