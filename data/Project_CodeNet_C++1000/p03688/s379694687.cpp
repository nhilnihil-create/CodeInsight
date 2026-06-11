#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll m = 100000; ll M = 0;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
    m = min(m,a[i]);
    M = max(M,a[i]);
  }
  if (M > m+1) {cout << "No" << endl; return 0;}
  if (M == m) {
    if (m == N-1 || (m <= N/2 && m >= 1)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
  ll n = 0;
  for (ll i = 0; i < N; i++) {
    if (a[i] == m) n++;
  }
  if (n > N-2) {cout << "No" << endl; return 0;}
  if (n+1 <= M && M <= n + (N-n)/2) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}