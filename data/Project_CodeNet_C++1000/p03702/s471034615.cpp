#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N, A, B;
ll h[100010];

bool check(ll m) {
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    ll rem = h[i] - m * B;
    if (rem <= 0) continue;
    cnt += (rem + (A-B) - 1) / (A-B);
  }
  return cnt <= m;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  ll ng = 0, ok = 1LL << 30;
  while (ok - ng > 1) {
    ll m = (ng + ok) / 2;
    if (check(m)) ok = m;
    else ng = m;
  }
  cout << ok << endl;

  return 0;
}