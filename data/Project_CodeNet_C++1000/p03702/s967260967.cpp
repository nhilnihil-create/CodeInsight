#include <iostream>
using namespace std; typedef long long ll;
int main() {
  ll n,a,b; cin>>n>>a>>b; ll h[n]; for(int i=0;i<n;i++) cin>>h[i];
  ll ng=0,ok=1e9;
  while(ok-ng>1) {
    ll md=(ng+ok)/2LL, lf=md;
    for(int i=0;i<n;i++) {
      ll x=h[i]-md*b;
      if (x>0) lf-=x/(a-b);
      if (x>0 && x%(a-b)!=0) lf--;
    }
    if (lf<0) ng=md; else ok=md;
  }
  cout<<ok<<endl;
}