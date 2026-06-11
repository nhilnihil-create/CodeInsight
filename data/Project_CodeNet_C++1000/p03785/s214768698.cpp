#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, C, K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  REP(i, N) { cin >> T.at(i); }
  sort(T.begin(), T.end());
  vector<ll> T2(N - 1);
  REP(i, N - 1) { T2.at(i) = T.at(i + 1) - T.at(i); }

  ll ans = 0;
  ll base = T.at(0);
  ll limit = base + K;
  ll current = base;
  ll count = 1;
  REP(i, N - 1) {
    current += T2.at(i);
    // cout << base << ":" << limit << ":" << current << ":" << count << ":" <<
    // ans
    //  << endl;

    if (count == C || current > limit) {
      base = current;
      limit = base + K;
      ans += (count + C - 1) / C;
      count = 1;
    } else {
      ++count;
    }
  }

  // cout << base << ":" << limit << ":" << current << ":" << count << ":" <<
  // ans
  //  << endl;

  ans += (count + C - 1) / C;

  cout << ans << endl;

  return 0;
}
