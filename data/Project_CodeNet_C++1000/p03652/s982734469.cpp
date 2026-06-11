#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N, M; cin >> N >> M;
  vector<ll> a[N];
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      ll x; cin >> x; a[i].push_back(x);
    }
  }
  ll p[N];
  set<ll> s;
  fill(p, p+N, 0);
  ll num = 0;
  ll res = 10000;
  while (num < M) {
    map<ll,ll> count;
    ll mx = 0;
    for (ll i = 0; i < N; i++) {
      if (p[i] < M) {
        count[a[i][p[i]]]++;
        mx = max(mx, count[a[i][p[i]]]);
      }
    }
    res = min(res, mx);
    for (ll i = 0; i < N; i++) {
      if (p[i] < M && count[a[i][p[i]]] == mx) {s.insert(a[i][p[i]]);}
    }
    for (ll i = 0; i < N; i++) {
      while (p[i] < M && s.count(a[i][p[i]])) p[i]++;
    }
    ll n = 10000;
    for (ll i = 0; i < N; i++) {n = min(n, p[i]);}
    num = n;
  }
  cout << res << endl;
}