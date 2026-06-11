#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, k, l;
int from_k[N], from_l[N];
map<pair<int, int>, int> ma;

int find(int x, int from[]) {
  if (x == from[x]) return x;
  return from[x] = find(from[x], from);
}

int main() {
  scanf("%d %d %d", &n, &k, &l);
  for (int i = 0; i < n; i++) {
    from_k[i] = i;
    from_l[i] = i;
  }
  for (int i = 0; i < k; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--, b--;
    int x = find(a, from_k), y = find(b, from_k);
    if (x != y) {
      from_k[x] = y;
    }
  }
  for (int i = 0; i < l; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--, b--;
    int x = find(a, from_l), y = find(b, from_l);
    if (x != y) {
      from_l[x] = y;
    }
  }
  for (int i = 0; i < n; i++) {
    pair<int, int> pr = make_pair(find(i, from_k), find(i, from_l));
    ma[pr]++;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    pair<int, int> pr = make_pair(find(i, from_k), find(i, from_l));
    printf("%d", (int) ma[pr]);
  }
  return 0;
}