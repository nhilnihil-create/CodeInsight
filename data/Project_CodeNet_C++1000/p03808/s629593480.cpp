#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int main() {
  ll N, s = 0;
  cin >> N;
  vector<ll> A(N + 1);
  rep(i, N) cin >> A[i], s += A[i];
  ll b = N * (N + 1) / 2;
  if (s % b != 0) return cout << "NO\n", 0;
  ll t = s / b;
  A[N] = A[0];
  rep(i, N) {
    ll d = A[i] + t - A[i + 1];
    if (d < 0 || d % N != 0) return cout << "NO\n", 0;
  }
  cout << "YES\n";
}
