#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int k,s;
  cin >> k>>s;
  int ans=0;
  rep(x,k+1){
    rep(y,k+1){
      if(s-x-y>=0 &&s-x-y<=k){
        ans++;
      }
    }
  }
  cout <<ans;
}
  
      