#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL<<60;

int main()
{
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> list(N);
  for (int i = 0; i < N; i++) {
    cin >> list[i];
  }

  ll ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans += min(B, A * (list[i + 1] - list[i]));
  }
  cout << ans << endl;
  return 0;
}