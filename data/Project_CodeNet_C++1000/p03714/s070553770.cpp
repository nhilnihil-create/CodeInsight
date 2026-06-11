#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N; scanf("%d", &N);
  vector<ll> A(3 * N);
  for (int i = 0; i < 3 * N; ++i) {
    scanf("%lld", &A[i]);
  }

  ll S = accumulate(A.begin(), A.begin() + N, 0LL);
  vector<ll> S1(N + 5);
  S1[0] = S;
  priority_queue<ll, vector<ll>, greater<ll>> que1(A.begin(), A.begin() + N);
  for (int i = N; i < 2 * N; ++i) {
    que1.push(A[i]);
    ll val = que1.top(); que1.pop();
    S += (A[i] - val);
    S1[i - N + 1] = S;
  }

  S = accumulate(A.begin() + 2 * N, A.end(), 0LL);
  vector<ll> S2(N + 5);
  priority_queue<ll> que2(A.begin() + 2 * N, A.end());
  S2[0] = S;
  for (int i = 1; i <= N; ++i) {
    que2.push(A[2 * N - i]);
    ll val = que2.top(); que2.pop();
    S += (A[2 * N - i] - val);
    S2[i] = S;
  }

  ll ans = -LLINF;
  for (int i = 0; i <= N; ++i) {
    ans = max(ans, S1[i] - S2[N - i]);
  }
  printf("%lld\n", ans);
  return 0;
}
