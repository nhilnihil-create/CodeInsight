#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  ll n_o = 0, n_2 = 0, n_4 = 0;
  rep(i, n) {
    ll a;
    cin >> a;
    if (a%4 == 0) n_4++;
    else if (a%2 == 0) n_2++;
    else n_o++;
  }
  if (n_o <= n_4) cout << "Yes" << endl;
  else if (n_o==n_4+1 && !n_2) cout << "Yes" << endl;
  else cout << "No" << endl;
}