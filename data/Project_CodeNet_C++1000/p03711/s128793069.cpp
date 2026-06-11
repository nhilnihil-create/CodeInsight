#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector <ll> v1 = {1, 3, 5, 7, 8, 10, 12};
  vector <ll> v2 = {4, 6, 9, 11};
  ll a, b; cin >> a >> b;
  ll tmp1, tmp2;
  rep(i, 7) {
    if (v1.at(i) == a) tmp1 = 1;
    if (v1.at(i) == b) tmp2 = 1;
  }
  rep(i, 4) {
    if (v2.at(i) == a) tmp1 = 2;
    if (v2.at(i) == b) tmp2 = 2;
  }
  if (a == 2) tmp1 = 3;
  if (b == 2) tmp2 = 3;
  if (tmp1 == tmp2) cout << "Yes" << endl;
  else cout << "No" << endl;
}