#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
signed main(){
  int x,y;
  cin >> x >> y;
  
  int a = abs( abs(x) - abs(y) );
  
  int ans = 1001001001001001001;
  
  if(  x + a == y ) ans = min(ans,a+0);
  if( -x + a == y ) ans = min(ans,a+1);
  if( -x - a == y ) ans = min(ans,a+1);
  if(  x - a == y ) ans = min(ans,a+2);
  
  cout << ans << endl;
  
  return 0;
}
