#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
#define MODSIZE 1000000007

int main(){
  int n,k;
  ll ans = 1;
  int i;

  scanf("%d %d", &n ,&k);

  ans = k;
  for(i = 1;i < n;i++){
    ans *= k - 1;
  }

  printf("%lld\n", ans);

  return 0;
}
