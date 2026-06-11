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
  vector<ll> former;
  former.push_back(S);
  priority_queue<ll, vector<ll>, greater<ll>> fque(A.begin(), A.begin() + N);
  for (int i = N; i < 2 * N; ++i) {
    fque.push(A[i]);
    ll val = fque.top(); fque.pop();
    S = S + A[i] - val;
    former.push_back(S);
  }

  ll T = accumulate(A.begin() + 2 * N, A.end(), 0LL);
  vector<ll> latter;
  latter.push_back(T);
  priority_queue<ll> lque(A.begin() + 2 * N, A.end());
  for (int i = 2 * N - 1; i >= N; --i) {
    lque.push(A[i]);
    ll val = lque.top(); lque.pop();
    T = T + A[i] - val;
    latter.push_back(T);
  }

  ll ans = -1 * LLINF;
  for (int i = 0; i < N + 1; ++i) {
    ans = max(ans, former[i] - latter[N - i]);
  }
  printf("%lld\n", ans);
  return 0;
}
