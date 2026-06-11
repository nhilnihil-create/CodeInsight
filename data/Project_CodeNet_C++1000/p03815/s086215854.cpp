#include <cstdio>
#define ll long long

int main() {
  ll x;
  scanf("%lld", &x);
  printf("%lld\n", x / 11 * 2 + (x % 11 + 5) / 6);
}