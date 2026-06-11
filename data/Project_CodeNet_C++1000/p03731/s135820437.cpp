#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  ll n,t;
  int i;
  ll a[200006];
  ll ans = 0;

  scanf("%lld %lld", &n, &t);

  for(i = 0;i < n;i++){
    scanf("%lld", &a[i]);
  }

  for(i = 1;i < n;i++){
    if((a[i] - a[i - 1]) >= t) ans += t;

    else ans += a[i] - a[i - 1];
  }

  ans += t;

  printf("%lld\n", ans);

  return 0;
}