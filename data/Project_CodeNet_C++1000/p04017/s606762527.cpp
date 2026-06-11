#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
ll n,L,q;
ll x[100010];
ll p[20][100010];
int main(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>x[i];
  cin>>L;
  for(int i=0;i<n;i++){
      ll l=i,r=n,mid;
      while(l<r-1){
          mid=(l+r)>>1;
          if(x[mid]<=x[i]+L)l=mid;
          else r=mid;
      }
      p[0][i]=l;
  }
  for(int d=0;d<19;d++)for(int i=0;i<n;i++){
      p[d+1][i]=p[d][p[d][i]];
  }
  cin>>q;
  while(q--){
      ll a,b; cin>>a>>b; a--,b--;
      if(a>b)swap(a,b);
      ll ans=1;
      for(int d=19;d>=0;d--){
          if(p[d][a]<b){
              ans+=(1<<d);
              a=p[d][a];
          }
      }
      cout<<ans<<endl;
  }
  return 0;
}

