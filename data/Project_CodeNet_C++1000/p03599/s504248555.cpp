#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  vector<ll> sugar;
  for (ll i = 0; i <= 3000; i++) {
    for (ll j = 0; j <= 1500; j++) {
      if (C*i+D*j <= F) {
        sugar.push_back(C*i+D*j);
      }
    }
  }
  sort(sugar.begin(), sugar.end());
  
  vector<ll> water;
  for (ll i = 0; i <= 30; i++) {
    for (ll j = 0; j <= 15; j++) {
      if (0< A*100*i+B*100*j && A*100*i+B*100*j <= F) {
        water.push_back(A*100*i+B*100*j);
      }
    }
  }
  vector<double> density;
  map<double, ll> dw;
  map<double, ll> ds;
  for (ll i = 0; i < water.size(); i++) {
    ll w = water[i];
    ll s = *(upper_bound(sugar.begin(), sugar.end(), min(F-w, E*w/100))-1);
    //cout << w << " " << s << endl;
    double d = (double)s/(double)(w+s);
    //cout << d << endl;
    density.push_back(d);
    dw[d] = w;
    ds[d] = s;
  }
  sort(density.begin(), density.end());
  double d = density[density.size()-1];
  //cout << d << endl;
  cout << dw[d]+ds[d] << " " << ds[d] << endl;
}