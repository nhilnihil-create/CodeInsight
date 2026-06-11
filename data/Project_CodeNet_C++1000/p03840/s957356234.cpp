#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll a[7];

int main(){
  rep(i,7) cin>>a[i];
  ll ans=0;
  if(a[0]!=0&&a[3]!=0&&a[4]!=0){
    rep(i,2){
      ll I=(a[0]-i)/2*2;
      ll J=(a[3]-i)/2*2;
      ll L=(a[4]-i)/2*2;
      ans=max(ans,I+J+L+3*i);
    }
  }else ans+=a[0]/2*2+a[3]/2*2+a[4]/2*2;
  cout<<ans+a[1]<<endl;
  return 0;
}
