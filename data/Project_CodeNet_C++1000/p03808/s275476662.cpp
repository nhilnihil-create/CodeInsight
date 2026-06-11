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

int main() {
  int n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  ll t = 1ll * n * (n + 1) / 2;
  if (sum % t) {
    cout << "NO" << endl;
    return 0;
  }
  ll k = sum / t;
  REP(i, n) {
    ll d = a[i] - (i == 0 ? a[n - 1] : a[i - 1]);
    d -= k;
    if (0 < d) {
      cout << "NO" << endl;
      return 0;
    }
    d = -d;
    if (d % n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}