#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  vector<int> c(n);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    c[a - 1]++;
    c[b - 1]++;
  }
  for(int i = 0; i < n; i++) {
    if(c[i] & 1) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}