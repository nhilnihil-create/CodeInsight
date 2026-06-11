#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll h,w,n;cin>>h>>w>>n;
  ll cnt[10];fill(cnt,cnt+10,0);
  map<pair<ll,ll>,ll>mp;
  for(ll i=0;i<n;i++){
    ll a,b;cin>>a>>b;
    pair<ll,ll> p=make_pair(a,b);
    mp[p]++;
    for(ll j=a-2;j<=a;j++){
      for(ll k=b-2;k<=b;k++){
        ll c=0;
        ll jud=0;
        for(ll l=j;l<=j+2;l++){
          for(ll m=k;m<=k+2;m++){
            if(l<1||l>h||m<1||m>w){
              jud=1;
              break;
            }
            if(mp[make_pair(l,m)]>0)c++;
          }
          if(jud==1)break;
        }
        if(jud==0){
          if(c==1)cnt[1]++;
          else{
            cnt[c-1]--;
            cnt[c]++;
          }
        }
      }
    }
  }
  ll sum=0;
  for(ll i=1;i<=9;i++)sum+=cnt[i];
  cnt[0]=(h-2)*(w-2)-sum;
  for(ll i=0;i<=9;i++){
    cout<<cnt[i]<<endl;
  }
}