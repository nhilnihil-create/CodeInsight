#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m;cin>>n>>m;
  if(abs(n-m)>1){
    cout <<0<<endl;
    return 0;
  }
  int64_t num=min(n,m);
  int64_t mod=1000000007;
  int64_t ans=1;
  if(n==m)ans=2;
  for(int64_t i=0;i<num;i++){
    ans*=(n-i);
    ans%=mod;
    ans*=(m-i);
    ans%=mod;
  }
  cout <<ans<<endl;
}