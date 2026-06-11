#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N;
  cin >> N;
  vector<long long> a(3 * N);
  rep(i, 3 * N)
  {
    cin >> a[i];
  }

  priority_queue<long long, vector<long long>, greater<long long>> big;
  priority_queue<long long> small;

  vector<long long> big_sum(N + 1), small_sum(N + 1);

  rep(i, N)
  {
    big_sum[0] += a[i];
    big.push(a[i]);

    small_sum[0] += a[3 * N - 1 - i];
    small.push(a[3 * N - 1 - i]);
  }

  rep(i, N)
  {
    big.push(a[N + i]);
    big_sum[i + 1] = big_sum[i] + a[N + i] - big.top();
    big.pop();

    small.push(a[2 * N - 1 - i]);
    small_sum[i + 1] = small_sum[i] + a[2 * N - 1 - i] - small.top();
    small.pop();
  }

  reverse(small_sum.begin(), small_sum.end());
  long long ans = INT64_MIN;
  rep(i, N + 1)
  {
    ans = max(ans, big_sum[i] - small_sum[i]);
  }
  cout << ans << endl;
  return 0;
}