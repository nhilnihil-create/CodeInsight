#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
ll num[100005],val[100005];
signed main(){
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(int i=0;i<n;i++) cin>>num[i]>>val[i];
  for(int d=0;d<=32;d++){
    ll b=k;
    if((d!=0)&&((b>>d)&1)==1) {
      b=(b>>d);
      b--;
    }
    else if(d!=0) continue;
    ll kans=0;
    for(int i=0;i<n;i++){
      ll kb=(num[i]>>d);
      if((b|kb)==b){
        kans+=val[i];
      }
    }
    ans=max(ans,kans);
  }
  cout<<ans<<endl;
}
