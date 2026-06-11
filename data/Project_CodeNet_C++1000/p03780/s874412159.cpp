#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;

int main()
{
  int N, K; scanf("%d %d", &N, &K);
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }
  sort(A.begin(), A.end(), greater<ll>());
  ll sum = 0;
  int ans = N;
  for (int i = 0; i < N; ++i) {
    if (sum + A[i] < K) {
      sum += A[i];
    }
    else {
      ans = min(ans, N - (i + 1));
    }
  }
  printf("%d\n", ans);
  return 0;
}
