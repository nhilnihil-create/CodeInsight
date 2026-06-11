#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  ll n,t;
  cin>>n>>t;

  ll a[111111];
  ll mi=MOD,ma=0;
  ll ans=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    mi=min(mi,a[i]);
    if(a[i]-mi==ma){
	 ans++;
    }else if(a[i]-mi>ma){
	 ans=1;
	 ma=a[i]-mi;
    }
  }

  cout<<ans<<endl;
  return 0;
}
