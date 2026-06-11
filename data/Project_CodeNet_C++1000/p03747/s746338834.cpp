#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  ll N,L,T; cin >> N >> L >> T;
  ll x[N], w[N];
  for (ll i = 0; i < N; i++) {
    cin >> x[i] >> w[i];
  }
  ll c0 = 0;
  if (w[0] == 1) {
    for (ll i = 1; i < N; i++) {
      if (w[i] == 2 && (x[i]-x[0]+L)%L< 2*T) {
        c0 += 1 + (2*T-1-((x[i]-x[0]+L)%L))/L;
      }
    }
  }
  if (w[0] == 2) {
    for (ll i = 1; i < N; i++) {
      if (w[i] == 1 && (x[0]-x[i]+L)%L< 2*T) {
        c0 += 1 + (2*T-1-((x[0]-x[i]+L)%L))/L;
      }
    }
  }
  //cout << c0 << endl;

  vector<P> v;
  for (ll i = 0; i < N; i++) {
    if (w[i] == 1) {
      v.push_back(P((x[i]+T)%L, w[i]));
    }
    if (w[i] == 2) {
      v.push_back(P((x[i]+(L-1)*T)%L, w[i]));
    }
  }
  ll xs = v[0].first; ll ws = v[0].second;
  ll ns;
  sort(v.begin(), v.end());
  for (ll i = 0; i < N; i++) {
    if (v[i].first == xs && v[i].second == ws) {
      ns = i; break;
    }
  }
  map<ll, ll> res;
  if (ws == 1) {
    for (ll i = ns; i < N; i++) {
      res[(c0+i-ns) % N] = v[i].first;
    }
    for (ll i = 0; i < ns; i++) {
      res[(c0+N-ns+i) % N] = v[i].first;
    }
  }
  if (ws == 2) {
    for (ll i = ns; i < N; i++) {
      res[(T*N-c0+i-ns) % N] = v[i].first;
    }
    for (ll i = 0; i < ns; i++) {
      res[(T*N-c0+N-ns+i) % N] = v[i].first;
    }
  }
  
  for (ll i = 0; i < N; i++) {
    cout << res[i] << endl;
  }
}