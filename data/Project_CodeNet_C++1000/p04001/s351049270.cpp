#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  string S;
  cin>>S;
  ll sum=0;
  for(int bit=0;bit<(1<<S.size()-1);bit++){
    ll t=S[0]-'0';
    for(int i=0;i<S.size()-1;i++){
      if(bit&(1<<i)){
        sum+=t;
        t=S[i+1]-'0';
      }else{
        t=t*10;
        t+=S[i+1]-'0';
      }
    }
    sum+=t;
  }
  
  cout<<sum<<endl;
}