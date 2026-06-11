#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = (long long)1e16 + 1000ll;
int nor,v,n = 50,t,m,k,ans[55];
signed main() {
  scanf("%lld",&k);
  t = k % n;
  m = k / n;
  nor = n - 1 + m - t;
  ans[1] = n - 1 + m + n * t;
  for (int i = 2 ; i <= n ; ++ i)
    ans[i] = nor;
  for (int i = 1 ; i <= n ; ++ i) {
    while (ans[i] > MAX)
      ans[i] -= n+1, ans[i+1] += n+1;
  }
  printf("%lld\n",n);
  for (int i = 1 ; i <= n ; ++ i)
    printf("%lld ",ans[i]);
  puts("");
  return 0;
}