#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll k;
  scanf("%lld", &k);
  vector<ll> a(50);
  for (int i = 0; i < 50; i++) {
    a[i] = i;
  }
  ll moves = 0;
  for (int i = 0; i < 50; i++) {
    ll quot = k / 50;
    moves += quot;
    a[i] += quot * 50;
    for (int j = 0; j < 50; j++) {
      if (i == j) continue;
      a[j] -= quot;
    }
  }
  for (int i = 0; i < 50 && moves < k; i++, moves++) {
    a[i] += 50;
    for (int j = 0; j < 50; j++) {
      if (i == j) continue;
      a[j]--;
    }
  }
  printf("50\n");
  for (int i = 0; i < 50; i++) {
    if (i) printf(" ");
    printf("%lld", a[i]);
  }
  printf("\n");
  return 0;
}
