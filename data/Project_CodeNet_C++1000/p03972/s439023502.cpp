#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll w,h;cin>>w>>h;
  vector<ll> p(w),q(h);
  ll ans=0;
  for(ll i=0;i<w;i++){
    cin>>p[i];
    ans+=p[i];
  }
  sort(p.begin(),p.end());
  ll sum[w+1];
  sum[0]=0;
  for(ll i=0;i<w;i++){
    sum[i+1]=sum[i]+p[i];
  }
  for(ll i=0;i<h;i++){
    cin>>q[i];
    ans+=q[i];
    ll c=lower_bound(p.begin(),p.end(),q[i])-p.begin();
    ans+=sum[c]+q[i]*(w-c);
  }
  cout<<ans<<endl;
}