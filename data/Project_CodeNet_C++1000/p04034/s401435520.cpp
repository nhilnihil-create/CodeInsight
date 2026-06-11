#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> x(M), y(M);
  for (int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<bool> has_red(N, false);
  vector<ll> ball_cnt(N, 1);
  has_red[0] = true;
  for (int i = 0; i < M; i++) {
    if (has_red[x[i]]) has_red[y[i]] = true;
    ball_cnt[x[i]]--;
    ball_cnt[y[i]]++;
    if (ball_cnt[x[i]] == 0) has_red[x[i]] = false;
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (has_red[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}