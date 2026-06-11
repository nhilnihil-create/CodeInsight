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
  ll n,k;
  ll a[111111],b[111111];
  ll ans=0;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
    
    int f=0;
    for(int j=0;j<=30;j++){
	 if((a[i]>>j&1)&&((k>>j&1)==0))f=1;
    }
    if(f)continue;
    ans+=b[i];
  }

  //cout<<ans<<endl;

  for(int i=0;i<=30;i++){
    if((k>>i&1)==0)continue;
    //    dbg(i);
    ll tmp=0;
    ll r=k-(1LL<<i);
    for(int j=0;j<n;j++){
	 int f=0;
	 for(int l=i;l<=30;l++){
	   if((a[j]>>l&1)&&((r>>l&1)==0))f=1;
	 }
	 if(f)continue;
	 tmp+=b[j];
    }
    ans=max(ans,tmp);
    //    dbg(ans);
  }

  cout<<ans<<endl;
  return 0;
}
