#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 100010
ll n,l,t;
ll x[N],w[N],ans[N];
int main(){
  cin>>n>>l>>t;
  for(int i=0;i<n;i++)cin>>x[i]>>w[i];
  ll hosl=x[0];
  for(int i=0;i<n;i++)x[i]-=hosl;
  bool hosf=(w[0]==2);
  if(hosf)for(int i=0;i<n;i++){
    w[i]=3-w[i];
    x[i]=(l-x[i])%l;
  }
  vector<ll> v;
  ll cnt=0,v0;
  for(int i=0;i<n;i++){
    if(w[i]==1){
      ll val=(x[i]+t)%l;
      v.push_back(val);
      if(i==0)v0=val;
      continue;
    }
    ll val=(x[i]-t)%l; if(val<0)val+=l;
    v.push_back(val);
    cnt+=t*2/l;
    ll rem=t*2%l;
    if(x[i]<=rem)cnt++;
    //cout<<"#"<<i<<" "<<cnt<<endl;
  }
  cnt%=n; if(hosf)cnt=(n-cnt)%n;
  //cnt...v0がans[cnt]
  sort(v.begin(),v.end());
  ll pnt=-1;
  for(int i=0;i<n;i++){
    if(v[i]==v0)pnt=i;
  }
  //cout<<v0<<" "<<pnt<<" "<<cnt<<endl;
  for(int i=0;i<n;i++){
    ans[cnt]=v[pnt];
    cnt++; cnt%=n;
    if(hosf)pnt+=n-1,pnt%=n;
    else pnt++,pnt%=n;
  }
  if(hosf)for(int i=0;i<n;i++)ans[i]=(l-ans[i])%l;
    
  for(int i=0;i<n;i++){
    ans[i]=(ans[i]+hosl)%l;
    cout<<ans[i]<<endl;
  }
  return 0;
}
