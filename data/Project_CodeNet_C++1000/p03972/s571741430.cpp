#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
signed main(){
  ll ans=0;
  ll w,h;
  vector<ll> p,q;
  p.push_back(0);
  q.push_back(0);
  cin>>w>>h;
  for(int i=0;i<w;i++){
    ll x;
    cin>>x;
    p.push_back(x);
    ans+=x;
  }
  for(int i=0;i<h;i++){
    ll y;
    cin>>y;
    q.push_back(y);
    ans+=y;
  }
  vector<ll> rsum;
  rsum.push_back(0);
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  for(int i=1;i<=w;i++) rsum.push_back(rsum[i-1]+p[i]);
  p.push_back(174417441744);
  for(int i=1;i<=h;i++){
    ll pos=lower_bound(p.begin(),p.end(),q[i])-p.begin();
    pos--;
    ll use_q=w-pos;
    ans+=rsum[pos]+(q[i]*use_q);
  }
  cout<<ans<<endl;
}
