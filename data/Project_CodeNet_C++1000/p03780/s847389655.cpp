#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(long long N, long long K, std::vector<long long> a) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll sum = 0;
    ll res = N;

    for (int i = 0; i < N; i++) {
      if (sum + a[i] < K) {
	  sum += a[i];
      } else {
	  res = min(res, N - i - 1);
      }
    }
    cout << res << endl;
}

int main() {

  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}
