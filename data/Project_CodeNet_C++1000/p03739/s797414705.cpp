#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll llbs(ll x) {
  if(x < 0) return -x;
  return x;
}

int main() {
  int N; cin >> N;
  vector<ll> a(N);
  for(int i = 0; i < N; i++) cin >> a.at(i);
  ll sumO = 0, sumE = 0, countO = 0, countE = 0;
  for(int i = 0; i < N; i++) {
    ll O = a.at(i), E = a.at(i);
    if(i % 2 == 0) {
      if(sumE + E <= 0) {
        countE += llbs(1 - (sumE + E));
        E = 1 - sumE;
      }
      if(sumO + O >= 0) {
        countO += llbs(-1 - (sumO + O));
        O = -1 - sumO;
      }
    } else {
      if(sumO + O <= 0) {
        countO += llbs(1 - (sumO + O));
        O = 1 - sumO;
      }
      if(sumE + E >= 0) {
        countE += llbs(-1 - (sumE + E));
        E = -1 - sumE;
      }
    }
    sumE += E;
    sumO += O;
  }
  cout << min(countE, countO) << endl;
}
