#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define ALL(v) v.begin(), v.end()

struct BIT {
  vector<ll> data;
  int N;

  BIT(int n) {
    N = 1;
    while (N < n) N *= 2;
    N *= 2;
    data = vector<ll>(N+1);
  }

  void add(int i, ll x) {
    for (int k = i; k <= N; k += k&-k) data[k] += x;
  }

  void update(int i, ll x) {
    add(i, x-get(i));
  }

  ll sum(int i) {
    ll res = 0;
    for (int k = i; k > 0; k -= k&-k) res += data[k];
    return res;
  }

  ll get(int i) {
    return sum(i) - sum(i-1);
  }
};

const int MAX = 2e5+10;
int N, K;
vii b;

int main() {
  cin >> N >> K;
  ll value = 0, a;
  BIT bit(MAX);
  b.PB(MP(0,0));
  REP (i, N) {
    cin >> a;
    value += a - K;
    b.PB(MP(value, i+1));
  }
  sort(ALL(b));
  ll ans = 0;
  REP (i, N+1) {
    int m = b[i].second+1;
    ans += bit.sum(m);
    bit.add(m,1);
  }
  cout << ans << endl;
}