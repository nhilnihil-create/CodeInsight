#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> A;
ll Base, Skip, DSkip;
vector<ll> XSkip, XDSkip;
ll R = 1ll << 60;

int main() {
  cin >> N >> M;
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    --a;
    A.push_back(a);
  }
  for (ll i = 0; i < N - 1; ++i) {
    ll d = A[i + 1] - A[i];
    if (d < 0) d += M;
    Base += d;
    if (A[i] > A[i + 1]) {
      Skip += M - A[i] - 1;
      ++DSkip;
    }
  }
  XSkip.resize(M);
  XDSkip.resize(M);
  for (ll i = 0; i < N - 1; ++i) {
    ll d = A[i + 1] - A[i];
    if (d < 0) d += M;
    XSkip[A[i + 1]] += d - 1 + 1;
  }
  ++XDSkip[A[0]];
  --XDSkip[A[N - 1]];
  for (ll x = 0; x < M; ++x) {
    R = min(R, Base - Skip);
    Skip += DSkip;
    Skip -= XSkip[x];
    DSkip += XDSkip[x];
  }
  cout << R << endl;
  return 0;
}
