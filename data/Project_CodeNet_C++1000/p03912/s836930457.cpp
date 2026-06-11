#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec[100005],cnt,vs;
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    vec[a%m].push_back(a);
  }
  for(int i=0;i<m;i++){
    sort(vec[i].begin(),vec[i].end());
    int kn=0;
    for(int j=0;j<vec[i].size();j++){
      if(vec[i][j]==vec[i][j+1]){
        kn++;
        j++;
      }
    }
    cnt.push_back(kn);
    vs.push_back(vec[i].size());
  }
  ll ans=0;
  for(int i=1;i<(m-i);i++){
    ll pr=min(vs[i],vs[m-i]);
    ans+=pr;
    vs[i]-=pr;
    vs[m-i]-=pr;
  }
  for(int i=0;i<m;i++){
    if(i==0) ans+=vs[i]/2;
    else if(i*2==m) ans+=vs[i]/2;
    else ans+=min(vs[i]/2,cnt[i]);
  }
  cout<<ans<<endl;
}
