#include<bits/stdc++.h>
using namespace std;
int64_t mod=1e9+7;
int64_t f(int64_t x){
  int64_t y=1,i;
  for(i=2;i<=x;i++) y=y*i%mod;
  return y;
}
int main(){
  int64_t n,m;
  cin>>n>>m;
  if(abs(n-m)>1) cout<<0<<endl;
  else if(n!=m) cout<<f(n)*f(m)%mod<<endl;
  else if(n==m) cout<<f(n)*f(n)%mod*2%mod<<endl;
}