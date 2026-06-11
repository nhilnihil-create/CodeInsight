#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
set<pair<ll, ll>> AccIs;
ll BitMax;
vector<ll> Bit;
ll R;

void init() { Bit.resize(BitMax + 1); }
void add(ll i) {
  ++i;
  for (; i <= BitMax; i += (i & -i)) ++Bit[i];
}
ll sum(ll i) {
  ++i;
  ll res = 0;
  for (; i >= 1; i -= (i & -i)) res += Bit[i];
  return res;
}
int main() {
  cin >> N >> K;
  ll acc = 0;
  AccIs.insert(make_pair(0, 0));
  for (ll i = 0; i < N; ++i) {
    ll a;
    cin >> a;
    a -= K;
    acc += a;
    AccIs.insert(make_pair(acc, i + 1));
  }
  BitMax = N + 1;
  init();
  for (auto acci : AccIs) {
    ll i = acci.second;
    R += sum(i);
    add(i);
  }
  cout << R << endl;
  return 0;
}
