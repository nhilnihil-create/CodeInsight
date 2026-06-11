#include <bits/stdc++.h>
using namespace std;
int a[222222], b[222222], n;
bool check(int x) {
  b[n] = a[n]>=x;
  for (int i=1; i<n; i++) {
    b[n+i] = a[n+i]>=x;
    b[n-i] = a[n-i]>=x;
    if (b[n+i]==b[n+i-1] || b[n-i]==b[n-i+1]) return b[n+i-1];
  }
  return b[1];
}
int main () {
  scanf("%d", &n);
  for (int i=1; i<=2*n+1; i++) {
    scanf("%d", &a[i]);
  }
  int l = 1, r = 2*n-1, ans;
  while (l<=r) {
    int mid = (l+r)/2;
    if (check(mid)) {
      ans=mid;
      l=mid+1;
    } else {
      r=mid-1;
    }
  }
  printf("%d\n", ans);
  return 0;
}