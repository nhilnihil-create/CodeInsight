#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1, greater<int>());
  int j = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] < i) {
      j = i - 1;
      break;
    }
  }
  int gou = a[j] - j, gor = 0, h = j;
  while (j < n && a[j + 1] == h)
    j++, gor++;
  puts(((gor & 1) || (gou & 1)) ? ("First") : ("Second"));
  return 0;
}
