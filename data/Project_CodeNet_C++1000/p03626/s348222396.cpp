#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i=2;string s1,s2;cin>>n>>s1>>s2;
  long long ans=6;bool f=0;
  if(s1.at(0)==s2.at(0)){
    ans=3,f=1,i=1;
  }
  while(i<n){
    if(s1.at(i)==s2.at(i)){
      ans*=(f?2:1),f=1,i++;
    }else{
      ans*=(f?2:3),f=0,i+=2;
    }
    ans%=1000000007;
  }
  cout<<ans;
}