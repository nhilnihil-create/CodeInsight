#include <cstdio>
#define ll long long

int main() {
  ll n, a, b, x, px, o = 0;
  scanf("%lld %lld %lld %lld", &n, &a, &b, &px);
  for(int i = 0; i < n - 1; i++) {
      scanf("%lld", &x);
    o += (x - px) * a < b ? (x - px) * a : b;
    px = x;
  }
  printf("%lld\n", o);
}