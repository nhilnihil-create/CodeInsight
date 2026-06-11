#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

int main()
{
  int N; scanf("%d", &N);
  vector<ll> A(3 * N + 5, 0);
  ll pre_sum = 0, post_sum = 0;
  for (int i = 1; i <= 3 * N; ++i) {
    scanf("%lld", &A[i]);
    if (i <= N) { pre_sum += A[i]; }
    else if (i > 2 * N) { post_sum += A[i]; }
  }
  priority_queue<int, vector<int>, greater<int>> que1;
  for (int i = 1; i <= N; ++i) { que1.push(A[i]); }
  vector<ll> S(N + 5, -1);
  S[0] = pre_sum;
  for (int i = N + 1; i <= 2 * N; ++i) {
    int pos = i - N;
    que1.push(A[i]);
    ll val = que1.top(); que1.pop();
    S[pos] = max(S[pos - 1], S[pos - 1] + A[i] - val);
  }

  priority_queue<int> que2;
  for (int i = 2 * N + 1; i <= 3 * N; ++i) { que2.push(A[i]); }
  vector<ll> T(N + 5, -1);
  T[N + 1] = post_sum;
  for (int i = 2 * N; i >= N + 1; --i) {
    int pos = i - N;
    que2.push(A[i]);
    ll val = que2.top(); que2.pop();
    T[pos] = min(T[pos + 1], T[pos + 1] + A[i] - val);
  }

  ll ans = -1 * (ll)1e18;
  for (int i = N; i <= 2 * N; ++i) {
    ans = max(ans, S[i - N] - T[i - N + 1]);
  }
  printf("%lld\n", ans);
  return 0;
}
