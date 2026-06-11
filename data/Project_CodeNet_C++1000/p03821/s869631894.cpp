#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int n;
  ll acc = 0;
  scanf("%d", &n);
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) scanf("%lld %lld", &a[i], &b[i]);
  for(int i = n - 1; i >= 0; i--) {
    a[i] += acc;
    if(a[i] % b[i]) acc += b[i] - a[i] % b[i];
  }
  printf("%lld\n", acc);
}