#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll res = 0;
  for (ll i = 0; i < N-1; i++) {
    ll n = a[i]/2;
    res += n;
    a[i] -= n*2;
    if (a[i] == 1 && a[i+1] > 0) {
      res++; a[i]--; a[i+1]--;
    }
  }
  res += (a[N-1]/2);
  cout << res << endl;
}