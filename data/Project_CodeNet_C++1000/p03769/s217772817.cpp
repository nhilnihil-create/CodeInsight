#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 550
typedef long long ll; 
using namespace std;
ll n;
int h[N], htot;
inline void Insert(int p) {
  for (int i = htot; i > p; --i) swap(h[i], h[i + 1]);
  h[p + 1] = ++htot;
}
int main() {
  scanf("%lld", &n); ++n;
  int j = 0;
  while ((1ll << j) <= n) ++j;
  --j;
  for (int i = 1; i <= j; ++i) h[i] = i;
  htot = j;
  for (int i = j - 1; ~i; --i) if (n & (1ll << i)) {
    Insert(i);
  }
  printf("%d\n", htot + 100); 
  for (int i = 1; i <= htot; ++i)  printf("%d ", h[i]);
  for (int i = 1; i < 100; ++i) printf("%d ", i); 
  puts("100");
  return 0;
}
