#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;

template<typename tp> inline void read(tp &x) {
  x = 0; char c = getchar(); int f = 0;
  for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if (f) x = -x;
}
const int N = 3e5 + 233;
int n, m, K;
int a[N], b[N], tmp[N];
vector <int> pw[233], E, id;
inline vector <int> uni(vector <int> &a, vector <int> &b) {
  vector <int> ans(n + 1);
  for (int i = 1; i <= n; i ++)
    ans[i] = b[a[i]];
  return ans;
}

inline void getT(void) {
  pw[0] = id;
  for (int i = 1; i <= 62; i ++)
    pw[i] = uni(pw[i - 1], pw[i - 1]);
  E.resize(n + 1);
  for (int i = 1; i <= n; i ++)
    E[i] = i;
  for (int k = 62; k >= 0; k --) {
    if (K >> k & 1)
      E = uni(E, pw[k]);
  }
}

main(void) {
  read(n);
  for (int i = 1; i <= n; i ++)
    read(a[i]);
  for (int i = 1; i <= n; i ++)
    b[i] = a[i] - a[i - 1];
  read(m); read(K);
  id.resize(n + 1);
  for (int i = 1; i <= n; i ++)
    id[i] = i;
  for (int i = 1; i <= m; i ++) {
    int x; read(x); swap(id[x], id[x + 1]);
  }
  getT();
  for (int i = 1; i <= n; i ++)
    tmp[i] = b[E[i]];
  for (int i = 1; i <= n; i ++)
    tmp[i] += tmp[i - 1];
  for (int i = 1; i <= n; i ++) {
    printf("%.10Lf\n", (long double) tmp[i]);
  }
}
