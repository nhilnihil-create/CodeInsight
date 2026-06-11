#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int n; ll l,t;
vector<ll> x;
vector<int> w;

int main() {
  cin >> n >> l >> t;
  x.resize(n); w.resize(n);
  for (int i = 0; i < n; i++) cin >> x[i] >> w[i];
  vector<ll> tmp(n);
  for (int i = 0; i < n; i++) {
    if (w[i] == 1) tmp[i] = (x[i] + t) % l;
    else tmp[i] = ((x[i] - t) % l + l) % l;
  }
  sort(tmp.begin(), tmp.end());
  ll count = 0;
  for (int i = 0; i < n; i++) {
    if (w[i] == 1) count -= (t - (l - x[i]) + l) / l;
    else count += (t - (x[i] + 1) + l) / l;
  }
  count = (count % n + n) % n;
  vector<ll> res(n);
  for (int i = 0; i < n; i++) res[(i+count)%n] = tmp[i];
  for (int i = 0; i < n; i++) cout << res[i] << endl;

  return 0;
}