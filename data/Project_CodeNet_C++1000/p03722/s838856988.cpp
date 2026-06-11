#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  vector<ll> c(M);
  for (int i = 0; i < M; i++) cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;

  ll oo = 0x1000000000000000LL;
  vector<ll> d(N, -oo);
  d[0] = 0LL;
  ll d1, d2;
  for (int i = 0; i < 2 * N; i++) {
    for (int j = 0; j < M; j++) d[b[j]] = max(d[b[j]], d[a[j]] + c[j]);
    if (i == N - 1) d1 = d[N - 1];
    if (i == 2 * N - 1) d2 = d[N - 1];
  }
  if (d1 == d2)
    cout << d1 << endl;
  else
    cout << "inf" << endl;
}
