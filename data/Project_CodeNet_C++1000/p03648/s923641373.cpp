#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll pow(ll x, ll e) {
  ll v = 1;
  for (; e; e>>=1) {
    if (e & 1) {
      v = v * x;
    }
    x = x * x;
  }
  return v;
}

ll MAX = pow(10, 16) + 1000;

bool solve(ll K, int N) {
  vector<ll> a(N), s(N);
  for (int i = 0; i < N; i++) {
    s[i] = K / N + (i < K % N);
    a[i] = N - 1 + s[i] * N - (K - s[i]);
    if (a[i] < 0 || MAX < a[i]) {
      return false;
    }
  }
  cout << N << endl;
  for (auto x: a) {
    cout << x << " ";
  }
  cout << endl;
  return true;
}

int main() {
  ll K;
  cin >> K;
  for (int N = 2; N <= 50; N++) {
    if (solve(K, N)) {
      break;
    }
  }
  return 0;
}
