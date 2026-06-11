//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  vector<ll> v(4);
  rep(i, 4) {
    cin >> v[i];
    v[i] *= pow(2, 3-i);
  }
  ll v_s = v[3];
  sort(all(v));
  ll n;
  cin >> n;
  if (v_s == v[0]) {
    ll n_s = n/2;
    cout <<  v[0]*n_s + v[1]/2*(n-n_s*2) << endl;
  } else {
    cout << v[0]*n/2 << endl;
  }
  return 0;
}