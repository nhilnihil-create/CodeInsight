#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
  ll sai[n];
  sai[0]=a[0];
  for(ll i=1;i<n;i++)sai[i]=max(sai[i-1],a[i]);
  vector<ll> v;
  for(ll i=0;i<n;i++)v.push_back(sai[i]);
  v.erase(unique(v.begin(),v.end()),v.end());
  ll tai[v.size()];
  ll now=0;
  for(ll i=0;i<n;i++){
    if(now==v.size())break;
    if(sai[i]==v[now]){
      tai[now]=i;
      now++;
    }
  }
  ll ko[v.size()];
  ll wa[v.size()];
  vector<ll> w;
  for(ll i=0;i<n;i++)w.push_back(a[i]);
  sort(w.begin(),w.end());
  for(ll i=0;i<n;i++){
    if(w[i]==v[0]){
      now=i;
      break;
    }
  }
  for(ll i=0;i<v.size();i++){
    if(i<v.size()-1){
      ll sum=0;
      for(ll j=now;;j++){
        if(w[j]==v[i+1]){
          ko[i]=j-now-1;
          wa[i]=sum;
          now=j;
          break;
        }
        sum+=w[j]-v[i];
      }
    }
    else{
      ko[i]=n-now;
      wa[i]=0;
    }
  }
  ll ans[n];
  fill(ans,ans+n,0);
  ll hav=ko[v.size()-1];
  for(ll i=v.size()-1;i>0;i--){
    ans[tai[i]]=wa[i-1]+hav*(v[i]-v[i-1]);
    hav=hav+ko[i-1]+1;
  }
  ll ss=0;
  for(ll i=0;i<n;i++){
    ss+=min(v[0],a[i]);
  }
  ans[0]=ss;
  for(ll i=0;i<n;i++){
    cout<<ans[i]<<endl;
  }
}
  
    
  