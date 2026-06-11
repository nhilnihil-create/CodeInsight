#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int cnt_digits(ll N){
  int digits=0;
  while(N>0){
    N/=10;
    digits++;
  }
  return digits;
}

int main(){
  ll n;
  cin>>n;
  int ans=cnt_digits(n);
  for(ll a=1LL;a*a<=n;++a){
    if(n%a!=0)continue;
    const ll b=n/a;
    
    const int cur=max(cnt_digits(a),cnt_digits(b));
    
    if(ans>cur){
      ans=cur;
    }
  }
  cout<<ans<<endl;
  return 0;
}