#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, x; cin >> N >> x;
  if (x == 1 || x == 2*N-1) {
    cout << "No" << endl; return 0;
  }
  vector<ll> v;
  for (ll i = 2; i <= 2*N-2; i++) {
    if (i == x) {continue;}
    else {v.push_back(i);}
  }
  ll a[2*N-1];
  a[N-2] = 2*N-1;
  a[N-1] = x;
  a[N] = 1;
  for (ll i = 0; i < N-2; i++) {
    a[i] = v[i];
  }
  for (ll i = N+1; i < 2*N-1; i++) {
    a[i] = v[i-3];
  }
  cout << "Yes" << endl;
  for (ll i = 0; i < 2*N-1; i++) {
    cout << a[i] << endl;
  }
}