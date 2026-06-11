#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,type=0;
  int64_t ans=1,mod=1e9+7;
  vector<string> s(2);
  cin>>n>>s.at(0)>>s.at(1);
  for(i=0;i<n;i++){
    if(s.at(0).at(i)==s.at(1).at(i)){
      if(type==0) ans=ans*3%mod;
      else if(type==1) ans=ans*2%mod;
      type=1;
    }
    else if(i<n-1&&s.at(0).at(i)==s.at(0).at(i+1)){
      if(type==0) ans=ans*6%mod;
      else if(type==1) ans=ans*2%mod;
      else if(type==2) ans=ans*3%mod;
      type=2;
      i++;
    }
  }
  cout<<ans<<endl;
}