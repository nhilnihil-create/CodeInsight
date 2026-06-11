#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
ll cost[200005]={0};
signed main(){
  ll n,x,ans=0;
  cin>>n>>x;
  for(int i=0;i<n;i++) {
    cin>>cost[i];
    ans+=cost[i];
  }
  for(int i=0;i<n;i++) {
    cost[i+n]=cost[i];
  }
  for(ll i=1;i<n;i++){
    multiset<ll> st;
    ll kans=i*x;
    for(int j=0;j<i;j++) st.insert(cost[j]);
    for(int j=i;j<n+i;j++){
      st.insert(cost[j]);
      ll mincost=*(st.lower_bound(0));
      st.erase(cost[j-i]);
      kans+=mincost;
    }
    ans=min(ans,kans);
  }
  cout<<ans<<endl;
}
