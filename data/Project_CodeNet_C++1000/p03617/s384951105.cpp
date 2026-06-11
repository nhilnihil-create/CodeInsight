#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll q,h,s,d;
  cin>>q>>h>>s>>d;
  ll n;
  cin>>n;
  s=min(s,min(4*q,2*h));
  ll ans;
  if(n==1){
    ans=s;
  }else if(n%2==0){
    ans=min(d*(n/2),s*n);
  }else{
    ans=min(d*(n/2)+s,s*n);
  }
  cout<<ans<<endl;
}