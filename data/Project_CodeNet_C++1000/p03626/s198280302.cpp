#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
  int n,i;string s1,s2;cin>>n>>s1>>s2;
  ll ans;bool f;
  if(s1.at(0)==s2.at(0)){
    ans=3;
    f=1;
    i=1;
  }else{
    ans=6;
    f=0;
    i=2;
  }
  while(i<n){
    if(s1.at(i)==s2.at(i)){
      ans*=(f?2:1);
      f=1;
      i++;
    }else{
      ans*=(f?2:3);
      f=0;
      i+=2;
    }
    ans%=(ll)1e9+7;
  }
  cout<<ans;
}