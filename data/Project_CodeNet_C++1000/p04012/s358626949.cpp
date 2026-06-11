#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using pint = pair<int, int>;

int main() {
  string w;
  cin >> w;
  vector<int> v(26, 0);
  rep(i, 0, w.size()) v[w[i] - '0' - 49]++;
  rep(i, 0, 26) {
    if (v[i] % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
