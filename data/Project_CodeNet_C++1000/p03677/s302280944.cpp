#include <bits/stdc++.h>
using namespace std;
inline void chmax (long long& a, long long b) {
  if (a < b) a = b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> ivdif(2 * m + 1, 0);
  vector<int> fall(2 * m + 1, 0);
  long long sum = 0;
  for (int i = 0; i < n - 1; i++) {
    int crr = a[i];
    int nxt = a[i + 1];
    if (crr > nxt) nxt += m;
    ivdif[crr + 2]++;
    ivdif[nxt + 1]--;
    fall[nxt + 1] += nxt - crr - 1;
    sum += nxt - crr;
  }
  vector<long long> svg(2 * m + 1);
  long long tmp = 0;
  int ivs = 0;
  for (int i = 0; i <= 2 * m; i++) {
    ivs += ivdif[i];
    tmp += ivs - fall[i];
    svg[i] = tmp;
  }
  long long maxv = 0;
  for (int i = 1; i <= m; i++) {
    chmax(maxv, svg[i] + svg[i + m]);
  }
  long long ret = sum - maxv;
  cout << ret << '\n';
  return 0;
}