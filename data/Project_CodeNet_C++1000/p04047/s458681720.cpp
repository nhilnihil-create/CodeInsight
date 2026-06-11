#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 111;
 
int n;
int a[2*maxn];
bool buf;
 
int main() {
  buf = scanf("%d", &n);
  n <<= 1;
  for (int i = 1; i <= n; i++) {
    buf = scanf("%d", a+i);
  }
  sort(a+1, a+n+1);
  int res = 0;
  for (int i = 1; i <= n; i += 2)
    res += a[i];
  printf("%d\n", res);
  return 0;
}