#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> A;
ll Sum;
ll R = 1ll << 60;

int main() {
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; ++i) cin >> A[i];
  for (ll a : A) Sum += a;
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    sum += A[i];
    if (i != N - 1) R = min(R, abs(Sum - 2 * sum));
  }
  cout << R << endl;
  return 0;
}
