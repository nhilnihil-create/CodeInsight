#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
map<ll, ll> C;
ll R;

int main() {
  cin >> N;
  ll cnt = 0;
  for (ll i = 1; i <= N; ++i) {
    ll p;
    cin >> p;
    if (i == p)
      ++cnt;
    else {
      R += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  R += (cnt + 1) / 2;
  cout << R << endl;
  return 0;
}
