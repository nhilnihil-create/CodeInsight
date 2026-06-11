#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<ll, ll> p_ll;

int main() {
  int N; cin >> N;
  p_ll ord[N];
  rep(i,N) {
    int a; cin >> a; a--;
    ord[i] = make_pair(i,a);
  }
  sort(ord, ord+N, [](const p_ll &x, const p_ll &y){return x.second<y.second;});

  ll result = 0;
  set<ll> pos; pos.insert(-1); pos.insert(N);
  rep(i,N) {
    ll of = ord[i].first, os = ord[i].second;
    auto r = pos.upper_bound(of);
    auto l = r; l--;
    // cout << os << ": " << *l << " " << of << " " << *r << endl;
    result += (of-*l) * (*r-of) * (os+1);
    pos.insert(of);
  }
  cout << result << endl;
  return 0;
}