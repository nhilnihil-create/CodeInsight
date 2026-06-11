#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
signed main(){
  int N,M;
  cin>>N>>M;
  if(abs(N-M)>1){
    puts("0");
    return 0;
  }
  if(N==M){
    int ans=1;
    for(int i=1;i<=N;i++)
      ans=ans*i%mod;
    cout<<ans*ans%mod*2%mod<<endl;
    return 0;
  }
  int ans=1;
  for(int i=1;i<=N;i++)
    ans=ans*i%mod;
  for(int i=1;i<=M;i++)
    ans=ans*i%mod;
  cout<<ans<<endl;
}