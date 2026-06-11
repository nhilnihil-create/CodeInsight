#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  ll n,a,b; cin>>n>>a>>b;
  ll h[n]; for(int i=0;i<n;i++) cin>>h[i];
  ll ng=0, ok=1e9;
  while(ok-ng>1) {
    ll md=(ng+ok)/2;
    ll h2[n];
    for(int j=0;j<n;j++) h2[j]=max(0LL,h[j]-md*b);
    ll sm=0;
    for(int i=0;i<n;i++) sm+=h2[i]/(a-b)+(h2[i]%(a-b)!=0);
    if (sm<=md) ok=md; else ng=md;
    //cout<<sm<<" "<<md<<" "<<endl;
  }
  cout<<ok<<endl;
}
