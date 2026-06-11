#include <bits/stdc++.h>
using namespace std;

int main(){
  int k,s,ans;
  ans = 0;
  cin >> k >> s;
  for(int i=0; i<k+1; i++){
    for(int j=0; j<k+1; j++){
      if(s-i-j>=0 && s-i-j<=k){
        ans+=1;
      }
    }
  }
  cout << ans << endl;
}