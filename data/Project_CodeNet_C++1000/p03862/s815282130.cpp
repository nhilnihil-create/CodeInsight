#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  ll n,x;
  ll a[100006];
  ll ans = 0;
  ll t;

  scanf("%lld %lld", &n, &x);

  int i;
  for(i = 0;i < n;i++) scanf("%lld", &a[i]);

  for(i = 0;i < n - 1;i++){
    if(a[i] + a[i + 1] <= x) continue;

    t = a[i] + a[i + 1] - x;
    ans += t;

    if(a[i + 1] >= t) a[i + 1] -= t;

    else {
      t -= a[i + 1];
      a[i + 1] = 0;
      a[i] -= t;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
