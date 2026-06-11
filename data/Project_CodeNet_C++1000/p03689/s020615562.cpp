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

const int N = 501;

int mat[N][N];

int main() {
  /*
#ifndef ONLINE_JUDGE
  freopen("source.in", "r", stdin);
  freopen("source.out", "w", stdout);
#endif
  */
  int H = read(), W = read(), h = read(), w = read();
  for (int i = 1; i <= H; ++i)
    for (int j = 1; j <= W; ++j) 
      mat[i][j] = 1000;
  for (int x = h; x <= H; x += h)
    for (int y = w; y <= W; y += w) 
      mat[x][y] = -(((h * w - 1) * 1000) + 1);
  int res = 0;
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) res += mat[i][j];
  }
  if (res <= 0) {
    puts("No");
    return 0;
  } else {
    puts("Yes");
    for (int i = 1; i <= H; ++i) {
      for (int j = 1; j <= W; ++j) printf("%d ", mat[i][j]);
      puts("");
    }
  }
  return 0;
}
