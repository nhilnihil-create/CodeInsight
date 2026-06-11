#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(3*N);
  for (int i = 0; i < 3*N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  ll ans = 0;
  for (int i = 1; i <= 2*N; i++) {
    if (i % 2 == 1) ans += A[i];
  }
  cout << ans  << endl;
}
