#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(ll a, ll b) {
  if (a == 0) return 0;
  return b - 1 - (a - 1) % b;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  vector<ll> num_push(n, 0);
  num_push[n-1] = f(a[n-1], b[n-1]);
  ll sum_push = num_push[n-1];
  for (int i = n-2; i >= 0; --i) {
    a[i] += sum_push;
    num_push[i] = f(a[i], b[i]);
    sum_push += num_push[i];
  }
  cout << sum_push << endl;
  return 0;
}