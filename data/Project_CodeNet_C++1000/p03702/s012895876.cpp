#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

bool ok(ll N, vi& h, ll A, ll B, ll x) {
  ll y = 0;

  for (ll i = 0; i < N; i++) {
    if (h[i] > x * B) {
      y += (h[i] - x * B + A - B - 1) / (A - B);
    }
  }

  return y <= x;
}

int main() {
  ll N, A, B;
  cin >> N >> A >> B;

  vi h(N);
  for (ll i = 0; i < N; i++) {
    cin >> h[i];
  }

  ll l = 0;
  ll r = 1000000000;

  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (ok(N, h, A, B, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << r << endl;
}