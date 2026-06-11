#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 5;

vector < int > same(N, 0);

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector < int > x(n), cnt(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cnt[x[i] % m]++;
    same[x[i]]++;
  }

  if (m == 1) {
    cout << n / 2 << endl;
    return 0;
  }

  ll ans = 0;
  for (int i = 1; i < m; i++) {
    if (i == m / 2) continue;
    int tmp = min(cnt[i], cnt[m - i]);
    cnt[i] -= tmp;
    cnt[m - i] -= tmp;
    ans += tmp;
  }
  ans += cnt[0] / 2;
  ans += cnt[m / 2] / 2;
  cnt[0] = cnt[m / 2] = 0;
  for (int i = 0; i < N; i++) {
    int r = i % m;
    int tmp = min(cnt[r] / 2, same[i] / 2);
    cnt[r] -= 2 * tmp;
    ans += tmp;
  }

  cout << ans << '\n';
}
