#include<bits/stdc++.h>
using namespace std;

signed main(){

  string s;
  int k;
  cin>>s>>k;

  int n = s.size();
  auto op = [](char c){
    return 'z'-c+1;
  };
  for(int i=0;i<n;++i){
    if(s[i]!='a'){
      if(op(s[i])<=k){
        k -= op(s[i]);
        s[i] = 'a';
      }
    }
  }
  if(k>=1){
    k%=26;
    while(k--){
      if(s.back()=='z')s.back()='a';
      else s.back()++;
    }
  }
  cout<<(s)<<endl;

}