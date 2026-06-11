#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<ll> T(N), A(N);
  for (int i = 0; i < N; i++) cin >> T[i] >> A[i];

  for (int i = 1; i < N; i++) {
    ll x = max((T[i - 1] + T[i] - 1) / T[i], (A[i - 1] + A[i] - 1) / A[i]);
    T[i] *= x, A[i] *= x;
  }
  cout << T[N - 1] + A[N - 1] << endl;
}
