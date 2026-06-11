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

ll f(ll a, ll b) {
  if (a > b) swap(a, b);
  if (b % a == 0) {
    return 2 * a * (b / a) - a;
  } else {
    return 2 * a * (b / a) + f(b % a, a);
  }
}

int main() {
  ll n, x;
  cin >> n >> x;
  ll ans = n + f(x, n - x);
  cout << ans << endl;
  return 0;
}