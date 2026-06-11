#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  string s,a;
  cin>>s;
  a="CODEFESTIVAL2016";
  int ans=0;
  for(int i=0;i<16;i++){
    if(s[i]!=a[i]){
      ans+=1;
    }
  }
  cout<<ans;
}