#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ncr[51][51];
ll v[51];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ncr[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for (int j = 1; j < i; j++)
      ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
  }

  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 1; i <= n; i++)
    cin >> v[i];
  sort(v + 1, v + 1 + n);
  reverse(v + 1, v + 1 + n);

  double avg = 0;
  for (int i = 1; i <= a; i++)
    avg += v[i];
  avg /= a;

  ll ans = 0;
  if (v[1] == v[a]) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (v[i] == v[1])
        cnt++;
    for (int i = a; i <= min(b, cnt); i++)
      ans += ncr[cnt][i];
  } else {
    int cnt = 0, need = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i] == v[a])
        cnt++;
      if (v[i] == v[a] && i <= a)
        need++;
    }
    ans = ncr[cnt][need];
  }

  cout << fixed << setprecision(10) << avg << endl;
  cout << ans << endl;
}
