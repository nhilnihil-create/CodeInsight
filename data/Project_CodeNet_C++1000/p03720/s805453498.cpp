#include <bits/stdc++.h>
using namespace std;
int n, m, i, a, b;
int freq[55];

int main() {
  //freopen("test.in", "r", stdin);
  scanf("%d %d\n", &n, &m);

  for (int i=0; i < m; i++) {
    scanf("%d %d\n", &a, &b);

    freq[a]++;
    freq[b]++;
  }

  for (int i = 1; i <= n; i++) {
    printf("%d\n",freq[i]);
  }

  return 0;
}