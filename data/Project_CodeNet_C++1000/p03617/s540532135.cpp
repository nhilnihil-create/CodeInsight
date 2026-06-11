#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll q,h,s,d,n,o;scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
  o = min({q*4,h*2,s});
  if(d<o*2) printf("%lld\n",n/2*d+o*(n%2));
  else printf("%lld\n",o*n);
}