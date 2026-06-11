#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  ll n,t[100010],a[100010];
  cin>>n;
  for(int i=0;i<n;i++)cin>>t[i];
  for(int i=0;i<n;i++)cin>>a[i];
  ll p=1e9+7;


  ll fixh[100010]={};
  ll fixt[100010]={};
  ll fixa[100010]={};
  fixt[0]=t[0];
  fixa[n-1]=a[n-1];
  for(int i=1;i<n;i++){
    if(t[i-1]<t[i])fixt[i]=t[i];
    if(a[i-1]>a[i])fixa[i-1]=a[i-1];
  }
  
  bool is_miss=false;
  for(int i=0;i<n;i++){
    fixh[i]=max(fixa[i],fixt[i]);
    if(fixh[i]==0)continue;
    if(fixa[i]&&fixt[i]&&fixa[i]!=fixt[i])is_miss=true;
    if(fixh[i]>a[i])is_miss=true;
    if(fixh[i]>t[i])is_miss=true;
  }
  if(is_miss){
    cout<<0<<endl;
    return 0;
  }

  ll ans=1;
  for(int i=0;i<n;i++){
    if(fixh[i])continue;
    ans*=min(a[i],t[i]);
    ans%=p;
  }

  cout<<ans<<endl;
  
  return 0;
}
