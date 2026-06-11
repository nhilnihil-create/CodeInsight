#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> A(N);
  for (auto &p : A) cin >> p.first >> p.second;
  
  ll count = 0;
  for (ll i = N-1; i >= 0; i--) {
    ll by = (A[i].first + count) % A[i].second;
    if (by != 0) by = A[i].second -by;
    count += by;
  }
  
  cout << count << endl;
}