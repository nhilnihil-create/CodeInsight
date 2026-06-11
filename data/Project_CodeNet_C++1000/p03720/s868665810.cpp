#include <stdio.h>
#include<stdlib.h>
#define ll long long

int main(void){
  ll n,m;
  scanf("%lld %lld",&n,&m);
  ll array[n];
  for(ll i=0;i<n;++i) array[i] = 0;
  
  for(ll i=0;i<m;++i){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    --a;
    --b;
    array[a]++;
    array[b]++;
  }
  for(ll i=0;i<n;++i){
    printf("%lld\n",array[i]);
  }

  return 0;
}

