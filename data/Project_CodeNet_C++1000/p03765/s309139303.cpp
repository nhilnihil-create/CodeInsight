#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
char s[N], t[N];
int n, m, p[N], q[N];

int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);

  for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + (s[i] == 'A');
  for (int i = 1; i <= m; ++i) q[i] = q[i - 1] + (t[i] == 'A');

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int l1, r1;
    int l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);

    int X = (r1 - l1 + 1) - 2 * (p[r1] - p[l1 - 1]) + 3*N;
    int Y = (r2 - l2 + 1) - 2 * (q[r2] - q[l2 - 1]) + 3*N;
    
    puts((X % 3) == (Y % 3) ? "YES" : "NO");
  }
}

