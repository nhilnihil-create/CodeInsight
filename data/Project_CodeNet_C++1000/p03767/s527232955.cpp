#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,ans = 0;scanf("%lld",&n);
  ll a[n*3];
  for(i=0;i<n*3;i++) scanf("%lld\n",&a[i]);
  sort(a,a+n*3,greater<ll>());
  for(i=1;i<n*2;i+=2) ans += a[i];
  printf("%lld\n",ans);
}