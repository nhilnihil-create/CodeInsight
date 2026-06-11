#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int n;
  ll c = 0, d = 0, pm = 0, mp = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    pm += a;
    mp += a;
    if(pm * (i % 2 ? -1 : 1) <= 0) {
      c += abs(pm) + 1;
      pm = i % 2 ? -1 : 1;
    }
    if(mp * (i % 2 ? -1 : 1) >= 0) {
      d += abs(mp) + 1;
      mp = i % 2 ? 1 : -1;
    }
  }
  printf("%lld\n", min(c, d));
}