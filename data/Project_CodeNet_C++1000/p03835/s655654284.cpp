#include <bits/stdc++.h>
using namespace std;

int main() {

  int k,s;
  cin >> k >> s;
  int x,y,z,ans=0;
  for(x=0;x<=k;x++){
      if(x>s){
          break;
      }
      for(y=0;y<=k;y++){
          if(s-x-y<0){
              break;
          }else if(s-x-y<=k){
              ans++;
          }
      }
  }
  cout << ans << endl;

}