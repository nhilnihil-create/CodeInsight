#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll mod=1e9+7,ans=1;
  int n;
  int x;
  string s1,s2;
  cin>>n>>s1>>s2;
  if(s1[0]==s2[0]){
    ans=3;
    x=1;
  }
  else{
    ans=6;
    x=2;
  }
  int y=x;
  for(int i=y;i<n;i++){
    if(s1[i]==s2[i]){
      if(x==1){
        ans*=2;
        ans%=mod;
      }
      x=1;
    }
    else{
      if(x==1){
        ans*=2;
        ans%=mod;
      }
      else{
        ans*=3;
        ans%=mod;
      }
      x=2;
      i++;
    }
  }
  cout<<ans<<endl;
}