#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ar[100005]={0},gsum[100005]={0},rsum[100005]={0};
int main(){
  ll n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    ar[i]=a;
    gsum[i]=gsum[i-1]+max(a,(ll)0);
    rsum[i]=rsum[i-1]+a;
  }
  ll ans=0;
  for(int i=0;i<n-k+1;i++){
    ll ls=gsum[i];
    ll rs=gsum[n]-gsum[i+k];
    ll ms=max((ll)0,rsum[i+k]-rsum[i]);
    ans=max(ans,ls+ms+rs);
  }
  cout<<ans<<endl;
}
