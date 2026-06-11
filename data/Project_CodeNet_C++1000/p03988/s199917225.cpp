#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, cnt[N];

int main() {
  scanf("%d", &n);
  int maxp = 0, minp;
  for (int i = 1; i <= n; i++) {
    int vl;
    scanf("%d", &vl);
    cnt[vl]++;
    maxp = max(maxp, vl);
  }
  minp = (maxp + 1) / 2;
  for (int i = 1; i < minp; i++) {
    if (cnt[i]) {
      puts("Impossible");
      return 0;
    }
  }
  if (cnt[minp] != maxp % 2 + 1) {
    puts("Impossible");
    return 0;
  }
  for (int i = minp + 1; i <= maxp; i++) {
    if (cnt[i] < 2) {
      puts("Impossible");
      return 0;
    }
  }
  puts("Possible");
  return 0;
}