#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 100100100100100100;
int main(){
  ll n,i,ans = inf,All = 0,now = 0;scanf("%lld",&n);
  ll a[n];
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);All += a[i];
  }
  for(i=0;i<n-1;i++){
    now += a[i];
    ans = min(ans,abs(All-now-now));
  }
  printf("%lld\n",ans);
}