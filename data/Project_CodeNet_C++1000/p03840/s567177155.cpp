#include <cstdio>

inline long long in() {
  long long n = 0;
  char c = getchar_unlocked();
  while ('0' <= c && c <= '9') {
    n *= 10;
    n += (c - '0');
    c = getchar_unlocked();
  }
  return n;
}

inline void out(long long n) {
  long long N = n, rev; int count = 0;
  rev = N;
  if (N == 0) { putchar_unlocked('0'); return; }
  while ((rev % 10) == 0) { count++; rev /= 10;}
  rev = 0;
  while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10; }
  while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10; }
  while (count--) putchar_unlocked('0');
}

int main() {
  long long I = in(), O = in(), T = in(), J = in(), L = in();
  long long n = (I&1?I-1:I) + (J&1?J-1:J) + (L&1?L-1:L);
  if (I && J && L) {
    long m = (I&1?I-1:I-2) + (J&1?J-1:J-2) + (L&1?L-1:L-2) + 3;
    out((n<m?m:n) + O);
  } else {
    out(n + O);
  }
}