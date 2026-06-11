#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  string s,t; cin>>s>>t;
  long long ans=1;
  if(n==1){
    cout<<3<<endl;
    return 0;
  }
  bool flag =false;
  int i=0;
  while(i<n){
    if(i==0){
      if(s[0]==t[0] && s[1]==t[1]){
        flag=true;
        i+=2;
      }else if(s[0]==t[0]){
        i+=3;
      }else if(s[2]==t[2]){
        i+=3;
        flag=true;
      }
      else{
        i+=4;
        ans=3*2*1*2+3*2*1*1;
        continue;
      }
      ans=6;
      continue;
    }
    if(s[i]==t[i]){
      i++;
      if(flag){
        ans*=2;
      }else{
        flag=true;
      }
    }else{
      i+=2;
      if(flag){
        flag=false;
        ans*=2;
      }else{
        ans*=3;
      }
    }ans%=1000000007;
  }
  cout<<ans<<endl;
}