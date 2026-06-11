#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N],n,b[N];
bool check(int x) {
  for (int i = 1 ; i <= 2 * n - 1 ; ++ i)
    b[i] = (a[i] >= x);
  if (b[n] == b[n-1] || b[n] == b[n+1])
    return b[n];
  int lp = 0, rp = 0;
  while (b[n - lp] != b[n-lp-1] && lp < n) ++ lp;
  while (b[n + rp] != b[n+rp+1] && rp < n) ++ rp;
  if (lp < n || rp < n) {
    if (lp <= rp) return b[n-lp];
    else return b[n+rp];
  }
  return b[n] ^ (n&1) ^ 1;
}
int main() {
  scanf("%d",&n);
  for (int i = 1 ; i <= 2 * n - 1 ; ++ i)
    scanf("%d",&a[i]);
  int l = 1, r = 2*n - 1, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  printf("%d\n",ans);
  return 0;
}
