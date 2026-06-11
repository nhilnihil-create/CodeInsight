#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pos;
int main(){
  ll n;
  cin>>n;
  ll ps=1;
  ll ren=0;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    if(ren%2==1){
      ren++;
      a=pos[i-1]+1;
    }
    else{
      a=min(ps,a);
      if(i>0){
        if(a==pos[i-1]+1) ren++;
      }
      else ren=0;
    }
    pos.push_back(a);
    ps=a+2;
  }
  ll ans=1,cnt=0;
  ren=0;
  ll mod=1e9+7;
  for(ll i=0;i<n;i++){
    cnt++;
    if(pos[i]-pos[i-1]==1){
      ren++;
      if(ren%2==1){
        ans*=cnt;
        cnt--;
        ans%=mod;
      }
    }
    else ren=0;
  }
  for(ll i=cnt;i>=1;i--){
    ans*=i;
    ans%=mod;
  }
  cout<<ans<<endl;
}
