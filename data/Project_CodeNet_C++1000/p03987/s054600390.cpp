#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int main() {
  ll N; cin >> N;
  map<ll, ll> pos;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i]; pos[a[i]] = i+1;
  }
  set<ll> s;
  ll res = 0;
  ll m = INF; ll M = -1; 
  for (ll i = 1; i <= N; i++) {
    ll l, r;
    if (M > pos[i]) {r = *(s.lower_bound(pos[i]));}
    else {r = N+1;}
    if (m < pos[i]) {l = *(prev(s.lower_bound(pos[i])));}
    else {l = 0;}
    M = max(M, pos[i]); m = min(m, pos[i]);
    s.insert(pos[i]);
    //cout << r-l-1 << endl;
    res += i*(r-pos[i])*(pos[i]-l);
  }
  cout << res << endl;
}