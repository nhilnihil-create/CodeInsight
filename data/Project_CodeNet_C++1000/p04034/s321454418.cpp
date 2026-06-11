#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  int n,m;
  cin >> n >> m;
  
  int array_x[m], array_y[m];
  rep(i,m){
    cin >> array_x[i] >> array_y[i];
    array_x[i]--; array_y[i]--;
  }
  
  int num[n];
  rep(i,n) num[i] = 1;
  
  bool isRed[n];
  rep(i,n) isRed[i] = false;
  isRed[0] = true;
  
  rep(i,m){
    int x = array_x[i];
    int y = array_y[i];
    if(isRed[x]){
      isRed[y] = true;
      if(num[x] == 1) isRed[x] = false;
    }
    num[x]--; num[y]++;
  }
  
  int ans = 0;
  rep(i,n) if(isRed[i]) ans++;
  
  cout << ans << endl;
 
  return 0;
}