#define C
typedef long long readtype;

/* Header {{{ */
#ifdef C
#include <stdio.h>
#include <math.h>
#include <string.h>
#define isdigit(a) ((a) >= '0' && (a) <= '9' ? true : false)
template<typename type> type abs(type a) { return a < 0 ? -a : a; }
template<typename type> type min(type a, type b) { return a < b ? a : b; }
template<typename type> type beMin(type &a, type b) { return a = (a < b ? a : b); }
template<typename type> type max(type a, type b) { return a > b ? a : b; }
template<typename type> type beMax(type &a, type b) { return a = (a > b ? a : b); }
template<typename type> void swap(type &a, type &b) { type c; c = a; a = b; b = c; }
#endif

#ifdef Cpp
#include <bits/stdc++.h>
using namespace std;
#endif

typedef long long var;

readtype read() {
  readtype a = 0, c = getchar(), s = 0;
  while (!isdigit(c)) s |= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return s ? -a : a;
}
/* }}} */

int main() {
  /*
#ifndef ONLINE_JUDGE
  freopen("source.in", "r", stdin);
  freopen("source.out", "w", stdout);
#endif
  */
  int n = read(), a = 0, b = 0, anum = 0, bnum = 0;
  for (int i = 1; i <= n; ++i) {
    int x = read();
    if (!a) a = x, anum = 1;
    else if (x == a) anum++;
    else if (!b) b = x, bnum = 1;
    else if (x == b) bnum++;
    else return !puts("No");
  }
  if (a < b) swap(a, b), swap(anum, bnum);
  if (b && b != a - 1) return !puts("No");
  if (bnum) a -= bnum, n -= bnum;
  else {
    if (a == n - 1) return !puts("Yes");
    a--, n -= 2;
    if (a == 0) return !puts("Yes");
  }
  if (a <= 0 || a == n) return !puts("No");
  puts(a * 2 <= n ? "Yes" : "No");
  return 0;
}
