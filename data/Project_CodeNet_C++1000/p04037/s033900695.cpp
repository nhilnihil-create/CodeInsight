#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (a[i + 1] == i) {
      int pos = i + 1;
      while (pos < n && a[pos + 1] == i) pos++;
      if (a[i] > i) {
        if (!((a[i] - i) & 1) && !((pos - i) & 1)) {
          puts("Second");
          return 0;
        } else {
          puts("First");
          return 0;
        }
      } else {
        if (!((pos - i) & 1)) {
          puts("Second");
          return 0;
        } else {
          puts("First");
          return 0;
        }
      }
    }
    if (a[i + 1] < i) {
      if (!((a[i] - i) & 1)) {
        puts("Second");
        return 0;
      } else {
        puts("First");
        return 0;
      }
    }
  }
  return 0;
}