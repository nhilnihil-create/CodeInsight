#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  vector<ll> data;
  cin >> n;
  vector<ll> sum_data(n + 1);
  REP(i, n) {
    ll x;
    cin >> x;
    data.push_back(x);
  }
  sort(ALL(data));
  REP(i, n) {
    if (i == 0) {
      sum_data[0] = data[0];
    } else {
      sum_data[i] = sum_data[i - 1] + data[i];
    }
  }

  int t = 0;
  for (int i = n - 1; i > 0; i--) {
    if (data[i] > 2 * sum_data[i - 1]) {
      t = i;
      break;
    }
  }

  cout << n - t << endl;
}