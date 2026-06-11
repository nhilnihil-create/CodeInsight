#include <bits/stdc++.h>

using namespace std;

long long n, x;
bool buf;

int main() {
  buf = scanf("%lld %lld", &n, &x);
  printf("%lld\n", 3LL*(n-__gcd(n, x)));
  
  return 0;
}