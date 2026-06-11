#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int n; cin >> n;
  Graph arr(3, vi(n));
  rep(i,3) rep(j,n) cin >> arr[i][j];

  map<int, int> former, latter;
  for (auto v : arr[0]) ++former[v];
  for (auto v : arr[2]) ++latter[v];

  vl sum1(n+1), sum2(n+1);
  sum1[0] = accumulate(all(arr[0]), 0LL);
  sum2[0] = accumulate(all(arr[2]), 0LL);

  rep(i,n) {
    auto p = *begin(former);
    int k = p.first;
    if (arr[1][i] > k) {
      sum1[i+1] = sum1[i] + arr[1][i] - k;
      ++former[arr[1][i]];
      --former[k];
      if (former[k] == 0) former.erase(k);
    }
    else sum1[i+1] = sum1[i];
  }

  reverse(all(arr[1]));

  rep(i,n) {
    auto p = *rbegin(latter);
    int k = p.first;
    if (arr[1][i] < k) {
      sum2[i+1] = sum2[i] + arr[1][i] - k;
      ++latter[arr[1][i]];
      --latter[k];
      if (latter[k] == 0) latter.erase(k);
    }
    else sum2[i+1] = sum2[i];
  }

  reverse(all(sum2));

  ll ans = -1e14;
  rep(i,n+1) ans = max(ans, sum1[i]-sum2[i]);
  cout << ans << endl;
  return 0;
}
