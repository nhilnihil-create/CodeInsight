#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200;
int a[maxn], cnt;
int num[50], t;

inline void insert(int p, int x) {
  for (int i = cnt++; i > p; i--) a[i] = a[i - 1];
  a[p] = x;
}

int main () {
  ll n; cin >> n;
  for (int i = 0; n; i++) num[t++] = n & 1, n >>= 1;
  for (int i = 1; i < t; i++) a[cnt++] = i;
  for (int i = 1; i < t; i++) a[cnt++] = i;
  a[cnt++] = a[cnt++] = t;

  int cur = t + 1;
  for (int i = t - 2; i >= 0; i--)
    if (num[i]) insert(i, cur), a[cnt++] = cur++;

  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) printf("%d ", a[i]);
  return 0;
}
