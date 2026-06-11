#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  string A;
  cin >> A;
  vector<ll> alfa(26, 0);
  for (ll i = 0; i < A.size(); ++i) {
    alfa.at(A[i] - 'a') += 1;
  }
  // for (ll i = 0; i < 26; ++i) {
  //   cout << alfa.at(i) << " ";
  // }
  // cout << "\n";
  ll ans = (A.size() * (A.size() - 1)) / 2;
  for (ll i = 0; i < 26; ++i) {
    ans -= (alfa.at(i) * (alfa.at(i) - 1)) / 2;
  }
  ans += 1;
  cout << ans << "\n";
}
