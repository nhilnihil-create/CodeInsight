#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

template<typename T>
vector<vector<vector<T>>>
Make3DVector(int d1, int d2, int d3, T default_value) {
  return vector<vector<vector<T>>>(
      d1, vector<vector<T>>(d2, vector<T>(d3, default_value)));
}

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  vector<int64> cum_sum(n + 1);
  vector<int64> pos_cum_sum(n + 1);
  for (int i = 1; i <= n; i++) {
    cum_sum[i] = cum_sum[i - 1] + xs[i - 1];
    pos_cum_sum[i] = pos_cum_sum[i - 1] + max(xs[i - 1], 0LL);
  }

  int64 ans = INT64_MIN;
  for (int i = 0; i + k <= n; i++) {
    // [0, i), [i, i + k), [i + k, n)
    int64 sum = 0;
    sum += pos_cum_sum[i];
    sum += max(cum_sum[i + k] - cum_sum[i], 0LL);
    sum += pos_cum_sum[n] - pos_cum_sum[i + k];
    UpdateMax(ans, sum);
  }
  cout << ans << endl;
}