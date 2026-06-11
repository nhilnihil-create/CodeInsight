#include <bits/stdc++.h>
using namespace std;

int n, x;
int a, b, anum, bnum;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    if (!a) a = x, anum = 1;
    else if (x == a) anum++;
    else if (!b) b = x, bnum = 1;
    else if (x == b) bnum++;
    else return !puts("No");
  }
  if (a < b) swap(a, b), swap(anum, bnum);
  if (b && b != a - 1) return !puts("No");
  if (bnum) a -= bnum, n -= bnum;
  else if (a == n - 1) return !puts("Yes");
  if (a <= 0 || a == n) return !puts("No");
  puts(a * 2 <= n ? "Yes" : "No");
  return 0;
}
