#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
typedef long long ll;

int main (int argc, char **argv) {
  ll n, a, b;
  scanf("%lld %lld %lld", &n, &a, &b);
  if (a > b || (n==1 && a!=b)) {
    std::cout << "0" << std::endl;
    return 0;
  }
  ll ans = (n-2)*(b-a) + 1;
  printf("%lld\n", ans);
  return 0;
}
