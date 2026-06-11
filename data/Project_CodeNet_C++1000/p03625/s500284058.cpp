#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll N; cin >> N;
  ll a[N];
  map<ll,ll> count;
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
    count[a[i]]++;
  }
  vector<ll> v;
  for (ll i = 0; i < N; i++) {
    if (count[a[i]] >= 2) v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  ll n = v.size();
  if (n == 0) {cout << 0 << endl; return 0;}
  
  if (count[v[n-1]] >= 4) {cout << v[n-1]*v[n-1] << endl;}
  else if (count[v[n-1]] < v.size()) {cout << v[n-1]*v[n-1-count[v[n-1]]];}
  else {cout << 0 << endl;}
}