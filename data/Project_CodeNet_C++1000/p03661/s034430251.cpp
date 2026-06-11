#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; scanf("%d", &n);
  vector<long long> a(n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for(int i = 1; i < n; i++) {
    a[i] += a[i-1];
  }
  long long ans = 9e18;
  for(int i = 0; i+1 < n; i++) {
    ans = min(ans, abs((a.back() - a[i]) - a[i]));
  }
  printf("%lld\n", ans);
  return 0;
}