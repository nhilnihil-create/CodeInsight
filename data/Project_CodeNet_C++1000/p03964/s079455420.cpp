#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<int> T(N), A(N);
  for (int i = 0; i < (int)N; ++i) cin >> T[i] >> A[i];

  ll t = T[0], a = A[0];
  for (int i = 1; i < N; ++i) {
    ll kt = (t + T[i] - 1) / T[i], ka = (a + A[i] - 1) / A[i];
    if (kt * A[i] < a) {
      t = T[i] * ka;
      a = A[i] * ka;
      continue;
    }
    if (ka * T[i] < t) {
      t = T[i] * kt;
      a = A[i] * kt;
      continue;
    }
    t = T[i] * min(ka, kt);
    a = A[i] * min(ka, kt);
  }

  cout << t + a << endl;

  return 0;
}
