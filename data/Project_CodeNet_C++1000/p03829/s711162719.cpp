#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n,a,b;
  int x[100006];
  int i;
  ll ans = 0;

  scanf("%d %d %d", &n, &a, &b);
  for(i = 0;i < n;i++) scanf("%d", &x[i]);

  ll t;
  for(i = 0;i < n - 1;i++){
    t = x[i + 1] - x[i];
    if(t*a >= b) ans += b;
    else ans += t*a;
  }

  printf("%lld\n", ans);

  return 0;
}
