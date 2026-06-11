#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

// [1, n]
int bit[200020];

// return a_1 + ... + a_i
int sum(int i) {
  int s = 0;
  while (0 < i) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

// a_i += x
void add(int i, int x) {
  while (i <= 200020) {
    bit[i] += x;
    i += i & -i;
  }
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  ll a[n];
  REP(i, n) cin >> a[i];
  ll b[n + 1];
  b[0] = 0;
  for (int i = 1; i <= n; ++i) {
    b[i] = b[i - 1] + a[i - 1] - k;
  }
  vector<P> vc;
  for (int i = 0; i <= n; ++i) {
    vc.push_back(P(b[i], i));
  }
  sort(ALL(vc));
  int c[n + 1];
  for (int i = 0; i <= n; ++i) {
    auto it = lower_bound(ALL(vc), vc[i]);
    c[it->second] = it - vc.begin() + 1;
  }
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += sum(c[i]);
    add(c[i], 1);
  }
  cout << ans << endl;
  return 0;
}