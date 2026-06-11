#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string s;
  cin>>s;
  ll len=s.length();
  vector<ll> num(len);
  for(ll i=0;i<len;i++){
    num[i]=s.at(i)-48;
    //cout<<num[i]<<endl;
  }
  ll ans=0;
  for(ll bit=0;bit<(1<<len-1);bit++){
    ll res=0;
    ll tmp=num[0];
    for(ll i=0;i<len-1;i++){
      if(bit&(1<<i)){
        res+=tmp;
        
        tmp=num[i+1];
      }else{
        tmp=tmp*10;
        //cout<<tmp<<endl;
        tmp+=num[i+1];
      }
    }
    res+=tmp;
    ans+=res;
  }
  cout<<ans<<endl;
}