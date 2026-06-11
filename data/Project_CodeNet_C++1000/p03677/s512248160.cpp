#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power[200005]={0};
int main(){
  ll n,m;
  cin>>n>>m;
  ll ans=0,kans=0;
  vector<ll> num;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    num.push_back(a);
  }
  for(int i=0;i<n-1;i++){
    ll a=num[i],b=num[i+1];
    if(a>b) b+=m;
    power[a+2]++;
    power[b+1]--;
    ans+=b-a;
  }
  for(int i=1;i<=2*m;i++) power[i]+=power[i-1];
  for(int i=0;i<n-1;i++){
    ll a=num[i],b=num[i+1];
    if(a>b) b+=m;
    power[b+1]-=b-a-1;
  }
  for(int i=1;i<=2*m;i++) power[i]+=power[i-1];
  for(int i=1;i<=m;i++) kans=max(kans,power[i]+power[i+m]);
  cout<<ans-kans<<endl;
}
