#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a[3*n];for(ll i=0;i<3*n;i++)cin>>a[i];
  ll mi[3*n],ma[3*n];
  mi[n-1]=0;ma[2*n]=0;
  multiset<ll>f,s;
  for(ll i=0;i<n;i++){
    mi[n-1]+=a[i];
    ma[2*n]+=a[3*n-1-i];
    f.insert(a[i]);
    s.insert(a[3*n-1-i]);
  }
  for(ll i=n;i<2*n;i++){
    auto k=f.begin();
    //cout<<*k;return 0;
    if(a[i]>*k){
      mi[i]=mi[i-1]+a[i]-*k;
      f.erase(f.begin());
      f.insert(a[i]);
    }
    else mi[i]=mi[i-1];
  }
  for(ll i=2*n-1;i>=n;i--){
    auto k=s.end();
    k--;
    if(a[i]<*k){
      ma[i]=ma[i+1]+a[i]-*k;
      s.erase(k);
      s.insert(a[i]);
    }
    else ma[i]=ma[i+1];
  }
  ll ans=-100000000000000000;
  for(ll i=n-1;i<2*n;i++){
    //cout<<mi[i]<<" "<<ma[i+1]<<endl;
    ans=max(ans,mi[i]-ma[i+1]);
  }
  cout<<ans<<endl;
}
