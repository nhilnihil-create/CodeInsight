#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
// typedef pair<ll, ll> P;
typedef pair<int, int> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int w, h;
  cin >> w >> h;
  int p[w], q[h];
  REP(i, w) cin >> p[i];
  REP(i, h) cin >> q[i];
  vector<P> vc;
  REP(i, w) vc.push_back(make_pair(p[i], 1));
  REP(i, h) vc.push_back(make_pair(q[i], 0));
  sort(ALL(vc));
  ll ans = 0;
  int a = w + 1, b = h + 1;
  REP(i, w + h) {
    int cost = vc[i].first;
    int type = vc[i].second;
    if (type) {
      ans += 1ll * cost * b;
      a--;
    } else {
      ans += 1ll * cost * a;
      b--;
    }
  }
  cout << ans << endl;
  return 0;
}