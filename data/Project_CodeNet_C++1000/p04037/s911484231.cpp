#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100009;
int n, a[N], ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (i + 1 > a[i + 1]) {
      for (int j = i + 1; a[j] == i; j++) ans ^= 1;
      ans |= (a[i] - i) & 1;
      puts(ans ? "First" : "Second");
      return 0;
    }
  return 0;
}
