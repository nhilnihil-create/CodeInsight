#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int N;
  string S1,S2;
  cin>>N>>S1>>S2;
  ll ans=1;
  int i=0;
  bool flag=true;
  if(S1.at(i)==S2.at(i)){
    ans*=3;
    flag=false;
    i++;
  }else{
    ans*=6;
    flag=true;
    i+=2;
  }

  while(i<N){
    if(S1.at(i)==S2.at(i)){
      if(!flag){
        ans*=2;
        ans%=MOD;
      }
      flag=false;
      i++;
    }else{
      if(flag){
        ans*=3;
        ans%=MOD;
      }else{
        ans*=2;
        ans%=MOD;
      }
      flag=true;
      i+=2;
    }
  }
  cout<<ans<<endl;
}
