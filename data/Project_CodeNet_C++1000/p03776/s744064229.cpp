#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<long double> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(), v.end());
  vector<pair<long double, int>> p;
  int prev = 0;
  for (int i = 0; i <= n; i++) {
    if (v[i] != v[prev]) {
      p.emplace_back(make_pair(v[prev], i - prev));
      prev = i;
    }
  }
  sort(p.begin(), p.end(), greater<pair<long double, int>>());

  map<long double, ll> mp;

  auto nCk = [&](ll n, ll k) {
    ll comb = 1;
    for (ll i = 1; i <= k; i++) {
      comb *= n - i + 1;
      comb /= i;
    }
    return comb;
  };

  auto calc = [&](int m) {
    long double avg = 0.0;
    int cnt = 0;
    int i = 0;
    int add = 0;
    while (cnt < m && i < p.size()) {
      add = min(m - cnt, p[i].second);
      cnt += add;
      avg += p[i].first * add;
      i++;
    }
    i--;
    avg /= (long double)m;
    mp[avg] += nCk(p[i].second, add);
  };

  for (int len = a; len <= b; len++) {
    calc(len);
  }
  pair<long double, ll> res;
  res = make_pair(0.0, 0LL);
  for (auto e : mp) {
    if (e.first > res.first) {
      res.first = e.first;
      res.second = e.second;
    }
  }
  printf("%.12Lf\n", res.first);
  printf("%Ld\n", res.second);
  return 0; 
} 