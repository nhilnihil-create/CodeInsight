#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,ans = 0;scanf("%lld",&n);
  pair<ll,ll> p[n];
  for(i=0;i<n;i++) scanf("%lld%lld",&p[i].first,&p[i].second);
  for(i=n-1;i>=0;i--){
    p[i].first += ans;
    ans += ((p[i].first%p[i].second) ? p[i].second-p[i].first%p[i].second:0);
  }
  printf("%lld\n",ans);
}