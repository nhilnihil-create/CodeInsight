#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int w, a, b;
  cin >> w >> a >> b;
  int ans;
  if(a==b) ans = 0;
  else if(a<b) ans = b-a-w;
  else ans = a-b-w;
  if(ans<0) ans = 0;
  cout << ans << endl;
  return 0;
}